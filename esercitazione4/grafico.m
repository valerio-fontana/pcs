dati = load('times.dat');

x = dati(:,1);
bubble = dati(:,2);
insertion = dati(:,3);
selection = dati(:,4);
sort = dati(:,5);

loglog(x, bubble, 'r')
hold on 
loglog(x, insertion, 'g')
loglog(x, selection, 'b')
loglog(x, sort, 'k')
hold off

xlabel('Dimensione del vettore')
ylabel("Tempo di ordinamento")
legend('Bubble sort', 'Insertion sort', 'Selection sort', 'std::sort')
grid on