/**
 * SCALETTA DEL QUERY PROCESSING :
 *  1 -> normalizzare la query
 *  2 -> pulire la query
 *  3 -> tokenizzare la query
 *  4 -> stemmare la query
 *  5 -> prelevare le postings list di ogni token nella query e salvarle come skip list
 *  6 -> usare gli skip per portare tutte le posting lists al docid comune minore
 *  7 -> prelevare il doclen del documento da analizzare e calcolare le costanti relative al documento per il BM25F
 *  8 -> calcolare lo score del documento e inserire in nella top k usando un algoritmo di inserimento ordinato con liste
 * linkate oppure un semplice insertion sort (se k non è più grande di qualche centinaia è il migliore) sovrascrivendo
 * gli elementi che dovrebbero arrivare in posizione k+1
 *  9 -> stampare la top k
 */

#include "../headers/olestem/stemming/english_stem.h"
#include "../headers/body_normalization.hpp"
using namespace std;

int main(int argc, char const *argv[])
{

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    string query;
    cout << "Insert a query for the system: ";

    try
    {
        getline(cin, query);
    }
    catch (ifstream::failure &e)
    {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    // text processing of the query
    query = normalize_text(query);
    vector<string> tokens = tokenize_text(query);
    tokens = remove_stopwords(tokens);
    vector<string> stem_tokens = stemmer(tokens);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    return 0;
}