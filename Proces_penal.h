class Proces_penal: public Proces
{
	// membri privati, ai clasei
private:
	int dovezi;
	bool stadiu;

public:
	// constructor de baza
	Proces_penal (){
	}

	// constructor parametrizat
	Proces_penal (int dovezi, bool stadiu):Proces(nrProces, reclamant, reclamat){
		this->dovezi = dovezi;
		if (this->dovezi > 25)
			this->stadiu = 1;
		else
			this->stadiu = 0;
	}

	// destructor
	~Proces_penal (){
	}

	// metoda cu care modificam stadiul unui proces penal
	void modificare_stadiu (){
		this->stadiu = 1 - this->stadiu;
	}

    // metoda cu care obtinem stadiul unui proces penal
    virtual bool afisare_stadiu(){
    	return this->stadiu;
    }

	// citirea unui proces penal (bazata pe citirea unui proces in general,
	// plus alte cateva campuri)
    virtual void citire (istream &in){
    	Proces::citire(in);
		cout << "Dovezi: ";
		in >> this->dovezi;
		if (this->dovezi > 25)
			this->stadiu = 1;
		else
			this->stadiu = 0;
    	cout << string(25, '-') << "\n";
    }

	// afisarea unui proces penal (bazata pe afisarea unui proces in general,
	// plus alte cateva campuri)
    virtual void afisare (ostream &out){
    	Proces::afisare(out);
		cout << "\tDovezi: " << this->dovezi << "\n";
		cout << "\tStadiu: " << this->stadiu << "\n";
    	cout << string(40, '*') << "\n";
    }

    // supraincarcarea operatorului >>
	friend istream& operator>>(istream& in, Proces_penal& pp){
		pp.citire(in);
	    return in;
	}

    // supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& out, Proces_penal& pp){
		pp.afisare(out);
	    return out;
	}

    // supraincarcarea operatorului =
	Proces_civil& operator=(const Proces_penal &pp){
		this->nrProces = pp.nrProces;
		this->reclamant = pp.reclamant;
		this->reclamat = pp.reclamat;
		this->dovezi = pp.dovezi;
		this->stadiu = pp.stadiu;
	}
};