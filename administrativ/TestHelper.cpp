#include "TestHelper.h"

const json failJson = json::parse("{\"result\": \"fail\"}");
const json successJson = json::parse("{\"result\": \"success\"}");

json TestHelper::TestIerarhieClasaProdus() {
      string str = "check";

      // Test Constructori ProdusAlimentar
      ProdusAlimentar *pa = new ProdusAlimentar();
      ProdusAlimentar *pa2 = new ProdusAlimentar(str, 78, str, 7.89, str, 200);
      
      // Test Set ProdusAlimentar
      float val = 9.27;
      string taraOrigine = "Spania";
      
      pa->setLeiPerKg(val);
      pa->setTaraDeOrigine(taraOrigine);
      
      // Test Get ProdusAlimentar
      if (pa->getLeiPerKg() != val) {
        return failJson;
      }
      if (pa->getTaraDeOrigine() != taraOrigine) {
        return failJson;
      }

      // OPERATORI ProdusAlimentar ???

      // Test Construcori ProdusNealimentar
      ProdusNealimentar *pn = new ProdusNealimentar();
      ProdusNealimentar *pn2 = new ProdusNealimentar(str, 20, str, str, 4.78, 30, 40);
      
      // Test Set ProdusNealimentar
      int garantie = 5;
      float pret = 5.79;
      string producator = "Adibas";
      
      pn->setGarantieAni(garantie);
      pn->setPret(pret);
      pn->setProducator(producator);
      
      // Test Get ProdusNealimentar
      if (garantie != pn->getGarantieAni()) {
        return failJson;
      }

      if (pret != pn->getPret()) {
        return failJson;
      }

      if (producator != pn->getProducator()) {
        return failJson;
      }

      // Test Constructori ProdusRedus
      ProdusRedus *pr = new ProdusRedus();
      ProdusRedus *pr_ref = new ProdusRedus(str, 69, str, str, 4.20, 2, 60, 100);
      
      int procentReducere = 60;
      
      // Test Set ProdusRedus
      pr->setPret(pret);
      pr->setProcentReducere(procentReducere);

      // Test Get ProdusRedus
      if (pr->getPret() != pret) {
        return failJson;
      }

      if (pr->getProcentReducere() != procentReducere) {
        return failJson;
      }

      if (pr->pretDupaReducere() != pret * (100 - procentReducere)) {
        return failJson;
      }
      
      // Test Constructori ProdusReturnat
      ProdusReturnat *prt = new ProdusReturnat();
      ProdusReturnat *prt_ref = new ProdusReturnat(str, 69, str, str, 4.20, 5, str, 51);

      string motiv = "aiurea";
      // Test Set ProdusReturnat
      prt->setMotiv(motiv);

      // Test Get ProdusReturnat
      if (prt->getMotiv() != motiv) {
        return failJson;
      }
      
      // Test Constructori ProdusResigilat
      ProdusResigilat *pr_res = new ProdusResigilat();
      ProdusResigilat *pr_res2 = new ProdusResigilat(str, 5, str, str, 6.89, 25, 28, str, 29, 30);

      // Test Set ProdusResigilat
      int procent = 6;
      pr_res->setProcentUzura(procent);

      // Test Get ProdusResigilat
      if (procent != pr_res->getProcentUzura()) {
        return failJson;
      }
       
      return successJson;
    }

json TestHelper::TestIerarhieClasaUser() {
  
    // Variabile ajutatoare Adresa
    string check = "check";
    string judet = "Constanta";
    string oras = "SatulDeVacanta";
    string strada = "Strada Bogatanilor";
    int numar = 20;
    string bloc = "Cel Mai Tare Bloc";
    int apartament = 1000; 
    
    // Test Constructor Adresa
    Adresa *adr = new Adresa();
    Adresa *adr2 = new Adresa(check, check, check, 70, check, 20);

    // Test Set Adresa
    adr->setJudet(judet);
    adr->setOras(oras);
    adr->setStrada(strada);
    adr->setNumar(numar);
    adr->setBloc(bloc);
    adr->setApartament(apartament);

    // Test Get Adresa
    if (adr->getJudet() != judet) {
        return failJson;
    }
    if (adr->getOras() != oras) {
      return failJson;
    }
    if (adr->getStrada() != strada) {
      return failJson;
    }
    if (adr->getBloc() != bloc) {
      return failJson;
    }
    if (adr->getApartament() != apartament) {
      return failJson;
    }

    // OPERATOR << ????


    // Test Constructori UserPremium
    unordered_map<int, int> reduceri_test;
    reduceri_test[1] = 5; reduceri_test[3] = 10;
    UserPremium *up = new UserPremium();
    UserPremium *up2 = new UserPremium(check, check, check, 20, check, 200, check, 20, check, 30, 200, check, check, check, reduceri_test);

    // Variabile ajutatoare User
    string nume = "Salam";
    string prenume = "Florin";
    string email = "capitanulromaniei@gmail.com";
    int idUser = 1000;
    int cap = 10;

    // Test Set UserPremium (implicit si User)
    up->setNume(nume);
    up->setPrenume(prenume);
    up->setEmail(email);
    up->setIdUser(idUser);
    up->setDateFacturare(*adr);
    up->setDateLivrare(*adr2);
    up->setReduceri(reduceri_test);
    up->setCostAbonamentPremium(cap);

    // Test Get UserPremium
    if (up->getNume() != nume) {
      return failJson;
    }

    if (up->getPrenume() != prenume) {
      return failJson;
    }

    if (up->getEmail() != email) {
      return failJson;
    }

    if (up->getIdUser() != idUser) {
        return failJson;
    }

    if (up->getDateFacturare() != *adr) {
      return failJson;
    }

    if (up->getDateLivrare() != *adr2) {
      return failJson;
    }
    if (up->getReduceri() != reduceri_test) {
      return failJson;
    }
    if (up->getCostAbonamentPremium() != cap) {
      return failJson;
    }

    // Variabile ajutatoare UserNonPremium
    int costTransport = 20;

    // Test Constructor UserNonPremium
    UserNonPremium *unp = new UserNonPremium();
    UserNonPremium *unp2 = new UserNonPremium(check, check, check, 40, check, 60, check, 20, check, 50, 200, check, check, check, 3.40);

    // Test Set UserNonpremium
    unp->setCostTransport(costTransport);

    // Test Get UserNonpremium
    if (unp->getCostTransport() != costTransport) {
      return failJson;
    }

  return successJson;
}

json TestHelper::TestClasaCosProduse()
{
    // Test Constructori Cos Produse
    string check = "check";
    CosProduse *cp = new CosProduse();
    CosProduse *cp2 = new CosProduse(check);

    if (cp2 == NULL)
    {
      return failJson;
    }

    // Test Set + Metode CosProduse
    string metodaPlata = "Card";
    
    cp->setMetodaPlata(metodaPlata);
    cp->addProdus(5, 3);

    // Test Get + Metode CosProduse
    if (cp->getCantitate(5) != 3) 
    {
      return failJson;
    }

    // Map ajutator pentru verificarea operatiilor
    unordered_map<int, int> TestCos;
    TestCos[5] = 3;
    
    if (cp->getCos() != TestCos) 
    {
      return failJson;
    }

    cp->deleteProdus(5);
    TestCos.clear();

    if (cp->getCos() != TestCos) 
    {
      return failJson;
    }

    return successJson; 
}

  }
