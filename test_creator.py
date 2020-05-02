import random
random.seed(2020)

def crear_test(n):
    pares = list()
    for i in range(n):
        w, r = random.randint(1, 30), random.randint(1, 50)
        pares.append([w, r])
    return pares


if __name__ == "__main__":
    ns = list(range(1,31,1))
    resistencias = [1, 10, 20, 50, 75, 100]

    with open('tests_tp1.txt', 'a') as file:
        file.write("{}\n".format(len(ns)*len(resistencias)))
        for r in resistencias:
            for n in ns:
                file.write("{} {}\n".format(n, r))
                for p in crear_test(n):
                    file.write("{} {}\n".format(p[0], p[1]))
                file.write("\n")
        file.close()
    print("Process finished successfully")
