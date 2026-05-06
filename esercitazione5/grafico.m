dati = load('times.dat');

x = dati(:,1);
bubble = dati(:,2);
insertion = dati(:,3);
selection = dati(:,4);
merge = dati(:,5);
quick = dati(:,6);
quick_mod = dati(:,7);
sort = dati(:,8);

loglog(x, bubble, 'r')
hold on 
loglog(x, insertion, 'g')
loglog(x, selection, 'b')
loglog(x, merge, 'm')
loglog(x, quick, 'c')
loglog(x, quick_mod, 'y')
loglog(x, sort, 'k')
hold off

xlabel('Dimensione del vettore')
ylabel("Tempo medio di ordinamento")
legend('Bubble sort', 'Insertion sort', 'Selection sort', 'Merge sort', 'Quick sort', 'Quick sort modificato', 'std::sort')
grid on