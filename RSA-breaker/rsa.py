from math import gcd as bltin_gcd
import sympy


def czy_wzglednie_pierwsze(a, b):
    return bltin_gcd(a, b) == 1


#print(czy_pierwsza(169))

def sprawdzanie(e, n):
    p = 2
    q = 2
    pom = 100000
    pom_k = pom * 10
    i_p = 0
    i_q = 0
    lista = list(sympy.primerange(pom, pom_k*100))
    for i in range(pom, pom_k):
        if ((p-1)*(q-1) > e) and czy_wzglednie_pierwsze((p-1)*(q-1), e) and (p*q == n):
            print("p=%d\nq=%d" %(p ,q))
            break
        else:
            if(i_q+100 >= pom_k) or (i_p+100 >= pom_k ):
                break
            print(i_p)
            if i%2==0:
                p = lista[i_p]
                i_p += 1
            else:
                q = lista[i_q]
                i_q += 1


c=861270243527190895777142537838333832920579264010533029282104230006461420086153423
n=1311097532562595991877980619849724606784164430105441327897358800116889057763413423
e=65537



sprawdzanie(e, n)
#m=(c**d)%n



