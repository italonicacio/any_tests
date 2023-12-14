import numpy as np

# Função que abre um arquivo e salva um conjunto de vetores na forma coluna
def WriteVectorsFile(filename, N, *args):
    #Abre o arquivo no modo de escrita, ai é possivel salvar
    f = open(filename, 'w')

    for i in range(0, N):
        for j in range(0, len(args)):
            # %s é uma referencia a C, o printf de C utiliza o %s para strings

            f.write('%s ' %(args[j][i]))

        f.write('\n')

    # Fecha o arquivo
    f.close()


# Função que abre um arquivo e lê um conjunto de vetores na forma coluna e retorna uma matriz 
def ReadVectorsFile(filename):

    # loadtxt retornar os vetores em uma matriz de N x M, onde n é o tamanho dos vetores e M é o número de vetores
    aux = np.loadtxt(filename)

    return aux

# Nome do arquivo aonde vai ser salvo os vetores e de onde vai ser lido os vetores do arquivo
filename = 'test.txt'

v1 = [5, 4, 3]
v2 = [2, 4, 6]
v3 = [3, 6, 9]
v4 = [1, 5, 7]

WriteVectorsFile(filename, len(v1), v1, v2, v3, v4)


m = ReadVectorsFile(filename)

print(m)

# m[:, i] acessa a i-esima coluna da matriz que é o i-esimo vetor
# para acessar os demais vetores basta mudar o i
print(m[:, 0])

#ou pode transpor a matriz m 
mt = np.transpose(m)
# Para a acessar dessa forma mais intuitiva
print(mt[0])