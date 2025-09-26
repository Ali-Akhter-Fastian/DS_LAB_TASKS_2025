    #include<iostream>
    using namespace std;
    class Product{
        string name;
        double price;
        double stock;
        public:
        Product(){}
        Product(string name,double price,double stock){
            this->name=name;
            this->price=price;
            this->stock=stock;
        }
        void printProductDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Stock: "<<stock<<endl;
        }
        double getprice(){return price;}
        void setprice(double price){this->price=price;}
    };
    class Bundle{
        Product *product=NULL;
        int quantity=0;
        float discountpercentage=0;
        public:
        Bundle(Product *list,int num, int discount){
            this->product=new Product[num];
            for(int i=0;i<num;i++){
                product[i]=list[i];
            }
            this->discountpercentage=discount;
            this->quantity=num;
        }
        void AddProduct(Product &p){
            Product *temp=new Product[quantity+1];
            for(int i=0;i<quantity;i++){
                temp[i]=product[i];
            }
            temp[quantity]=p;
            delete[] product;
            product=temp;
            quantity++;
        }
        void ApplyDiscount(){
            for(int i=0;i<quantity;i++){
                double price = product[i].getprice() - (product[i].getprice()*(discountpercentage/100));
                product[i].setprice(price);
            }
        }
        void printBundleDetails(){
            for(int i=0;i<quantity;i++){
            cout<<endl<<"Product "<<i+1<<endl;
                product[i].printProductDetails();
            }
            
        }
        Bundle(Bundle &obj){
            this->product=obj.product;
            this->discountpercentage=obj.discountpercentage;
            this->quantity=obj.quantity;

        }
        // Bundle(Bundle &obj){
        //     this->product=new Product[obj.quantity];
        //     for(int i=0;i<obj.quantity;i++){
        //         this->product[i]=obj.product[i];
        //     }
        //     this->discountpercentage=obj.discountpercentage;
        //     this->quantity=obj.quantity;
        // }
    };
    int main(){
        Product p1("Product 1",10,100);
        Product p2("Product 2",20,200);
        Product p3("Product 3",30,300);
        Bundle b1(&p1,1,10);
        b1.AddProduct(p2);
        cout<<endl<<"BUNDLE 1"<<endl;
        b1.printBundleDetails();
        Bundle b2=b1;
        cout<<endl<<"BUNDLE 2"<<endl;
        b2.printBundleDetails();
        cout<<endl<<"APPLYING DISCOUNT TO PRODUCT OF BUNDLE 2"<<endl;
        b2.ApplyDiscount();
        cout<<endl<<"Bundle 2"<<endl;
        b2.printBundleDetails();
        //In case of shallow copy the prices of product in bundle 1 also change//
        cout<<endl<<"Bundle 1"<<endl;
        b1.printBundleDetails();
    }