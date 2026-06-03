    int positivos=0, negativos=0, neutros=0;
    for(int i=0;i<10;i++){
        cin >> num;
        if(num>0) positivos++;
        else if(num<0) negativos++;
        else neutros++;
    }
    cout << "Positivos: " << positivos << " Negativos: " << negativos << " Neutros: " << neutros << endl;