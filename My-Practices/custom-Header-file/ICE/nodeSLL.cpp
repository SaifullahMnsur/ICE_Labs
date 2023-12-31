template<typename T>
nodeSLL<T>::nodeSLL(): data(0), next(nullptr) {}
template<typename T>
nodeSLL<T>::nodeSLL(T value): data(value), next(nullptr) {}
template<typename T>
nodeSLL<T>::nodeSLL(T value, nodeSLL<T> *next_node): data(value), next(next_node) {}