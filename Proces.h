class Proces
{

// membri protected, pentru ca vom deriva
protected:
	int nrProces;
	string reclamant;
	string reclamat;
	static int totalProcese;

// membri/metode public, pentru a le putea accesa din alte clase
public:
	// constructor de baza
	Proces (){
		// la fiecare proces nou creat, creste variabila statica
		// referitoare la numarul de procese
		totalProcese++;
	}

	// constructor parametrizat
	Proces (int nrProces, string reclamant, string reclamat){
		totalProcese++;
		this->nrProces = nrProces;
		this->reclamant = reclamant;
		this->reclamat = reclamat;
	}

	// destructor
	~Proces(){
	}

	// getter pentru numarul unui proces
	int get_nr_proces (){
		return nrProces;
	}

	// getter pentru numarul total de procese
	static int total_nr_procese (){
		return totalProcese;
	}

	// initializator pentru numarul total de procese
	static void init_nr_procese (){
		totalProcese = 0;
	}

	// citirea unui proces
    virtual void citire(istream &in){
    	cout << "\n" << string(25, '-');
	    cout << "\nNumarul procesului: ";
	    in >> this->nrProces;
	    getchar();
	    cout << "Reclamant: ";
	    getline(in, this->reclamant);
	    cout << "Reclamat: ";
	    getline(in, this->reclamat);
    }        

    // afisarea unui proces
    virtual void afisare(ostream &out){
    	cout << string(10, '*');
    	cout << "  Numar proces: " << this->nrProces;
    	cout << "  " << string(10, '*') << "\n";
	    out << "\tReclamant: " << this->reclamant << "\n";
	    out << "\tReclamat: " << this->reclamat << "\n";
    }

    // Functii virtuale pentru a modifica/obtine stadiul unui proces
    // Au fost necesare pentru accesarea stadiului din clasa Proces,
    // nestiind exact in ce subclasa ne aflam.
    // Implementarile au fost facute in clasele derivate
    virtual void modificare_stadiu(){
    }

    virtual bool afisare_stadiu(){
    }

    // supraincarcarea operatorului >>
	friend istream& operator>>(istream& in, Proces& p){
		p.citire(in);
	    return in;
	}

	// supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& out, Proces& p){
		p.afisare(out);
	    return out;
	}

	// supraincarcarea operatorului =
	Proces& operator=(const Proces &p){
		this->nrProces = p.nrProces;
		this->reclamant = p.reclamant;
		this->reclamat = p.reclamat;
	}
};