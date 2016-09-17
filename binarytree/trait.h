#ifndef TRAIT_H
#define TRAIT_H
template <typename t>
class Asc{
public:
  bool operator ()(t a,t b){
    return a>b;
  }
};
template <typename t>
class Desc{
public:
  bool operator ()(t a,t b){
    return a<b;
  }
};

template<typename t>
struct traitAsc{
  typedef t t_data;
  typedef Asc<t_data> ord;
};
template<typename t>
struct traitDesc{
  typedef t t_data;
  typedef Desc<t_data> ord;
};

#endif // TRAIT_H