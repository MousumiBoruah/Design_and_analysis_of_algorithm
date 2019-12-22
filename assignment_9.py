def preceding(A, B):
    return_len = len(A) + len(B)
    i = 0
    while i < min(len(A), len(B)):
        if A[len(A)-i-1] == B[i]:
            i += 1
        else:
            break
    return_len -= i
    return return_len

def suceeding(A, B):
    return_len = len(A) + len(B)
    i = 0
    while i < min(len(A), len(B)):
        if A[i] == B[len(B)-i-1]:
            i += 1
        else:
            break
    return_len -= i
    return return_len

def graph(strings, graph):
    i = 0
    while i < len(strings):
        list_to_append = []
        j = 0
        while j < len(strings):
            if i == j:
                list_to_append.append(10000)
            else:
                list_to_append.append(min(preceding(strings[i], strings[j]), suceeding(strings[i], strings[j])))
            j += 1
        graph.append(list_to_append)
        i += 1
    return

def D_minimum_index(graph, list_to_search):
    min_index_i = -1
    min_index_j = -1
    min_index_val = 10000
    i = 0
    while i < len(list_to_search):
        y = graph[list_to_search[i]].index(min(graph[list_to_search[i]]))
        x = i
        if  graph[x][y] < min_index_val:
            min_index_i = x
            min_index_j = y
            min_index_val = graph[x][y]
        i += 1
    return min_index_j

def find_string(graph, strings):
    replace = []
    replace_length = 0
    result = strings[0]
    list_to_search = [0]
    len_list_to_search = len(list_to_search)
    k = 0
    while k < len(strings):
        graph[k][0] = 10000
        k += 1
    while(len(list_to_search) != len(strings)):
        min_index_j = D_minimum_index(graph, list_to_search)
        preceding_val = preceding(result, strings[min_index_j])
        suceeding_val = suceeding(result, strings[min_index_j])
        if preceding_val == suceeding_val:
            if strings[min_index_j] in result:
                list_to_search.append(min_index_j);
                k = 0
                while k < len(strings):
                    graph[k][min_index_j] = 10000
                    k += 1
            else:
                k = 0
                check = [min_index_j]
                while k < len(strings):
                    check.append(graph[k][min_index_j])
                    graph[k][min_index_j] = 10000
                    k += 1
                replace.append(check)
                replace_length += 1
        else:
            if preceding_val < suceeding_val:
                add_val = preceding_val - len(result)
                result = result + strings[min_index_j][len(strings[min_index_j]) - add_val : ]
            else:
                add_val = suceeding_val - len(result)
                result = strings[min_index_j][0 : add_val] + result
            list_to_search.append(min_index_j);
            k = 0
            while k < len(strings):
                graph[k][min_index_j] = 10000
                k += 1
        if len_list_to_search == len(list_to_search) - 1:
            k = 0
            while k < replace_length:
                val = replace[k][0]
                m = 1
                while m < len(replace[k]) - 1:
                    graph[m - 1][val] = replace[k][m]
                    m += 1
                k += 1
            replace = []
            replace_length = 0
            len_list_to_search = len(list_to_search)
    print result

def main():
    strings = ['AY8PMPAR', 'NGAT', 'ME', 'OME', 'ETINGAT2', '7MA', 'Y8PMPA', 'RKHO', 'ME', 'MEE', 'TIN', 'GAT27M', 'KHOME', 'MEETI', '27MAY8', 'PMP', 'ARKH']
    graph = []
    graph(strings, graph)
    find_string(graph, strings)

if __name__ == '__main__':
    main()
