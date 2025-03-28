class Knot {
    public:
      Knot(const double x, double y) : x_(x), y_(y) {}
      double add_up();

    private:
      double x_;
      double y_;
};