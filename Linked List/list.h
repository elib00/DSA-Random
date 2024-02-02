class List {
    public:
        virtual void insert(int) = 0;
        virtual int remove(int) = 0;
        virtual int get(int) = 0;
        virtual int search(int) = 0;
        virtual void print() = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
        virtual void addAt(int, int) = 0;
        virtual int removeAt(int) = 0;
};