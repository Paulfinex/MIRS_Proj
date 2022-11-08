#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/text_normalization.hpp"
#include "../headers/index_build.hpp"
#include "../headers/u8lib/u8.hpp"
#include <chrono>
#include <algorithm>
using namespace std;
/**
 * @brief Main method for document text processing
 *
 */
int main()
{

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int countBatch = 0;
    int countfortimedebug = 0;
    ifstream infile;
    ofstream outfile;
    vector<string> chunkBlock;
    string outPath = "../data/output/processed_docs.txt";

    try
    {
        infile.open("../data/input/collection.tsv");
        outfile.open(outPath, ios::app);
        if (!infile.is_open())
        {
            throw new ifstream::failure("Invalid input file for index building");
        }
        while (!infile.eof())
        {
            string docno;
            string docbody;

            // document-by-document reading of the documents
            getline(infile, docno, '\t');
            getline(infile, docbody, '\n');
            if (docbody.size() == 0)
                continue;
            docbody = u8lib::to_cppstring(u8lib::to_u8string(docbody));
            // Normalize docbody (remove special characters and lowercase)
            docbody = normalize_text(docbody);
            vector<string> tokens = tokenize_text(docbody);
            // Remove stopwords from docbody
            tokens = remove_stopwords(tokens);
            // Stemming over docbody's tokens
            vector<string> stem_tokens = stemmer(tokens);
            // Rebuild docbody from tokens
            string processed_docbody = vector_to_string(stem_tokens);
            // Add current document to chunk processing list
            chunkBlock.push_back(docno + "\t" + processed_docbody);
            // Increase chunk counter
            countBatch++;
            // Write processed documents to file every 5000 iteration
            if (countBatch > 0 && countBatch % 5000 == 0)
            {
                countfortimedebug++;
                std::chrono::steady_clock::time_point beginBatch = std::chrono::steady_clock::now();
                cout<<"Current File:"<<countBatch<<endl;
                for (string l : chunkBlock)
                {
                    outfile << l << "\n";
                }
                chunkBlock.clear();
                std::chrono::steady_clock::time_point endBatch = std::chrono::steady_clock::now();
                std::cout<<"Batch:"<<to_string(countfortimedebug)<< "- Time elapsed = " << std::chrono::duration_cast<std::chrono::milliseconds>(endBatch - beginBatch).count() << "[ms]" << std::endl;
            }
        }
        // Last chunk write to file
        for (string l : chunkBlock)
        {
            outfile << l << "\n";
        }
        chunkBlock.clear();
        outfile.close();
    }
    catch (ifstream::failure &e)
    {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time elapsed = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    // std::system("pause");
    return 0;
}
