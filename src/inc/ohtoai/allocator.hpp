
namespace ohtoai
{
    template <typename T>
    class allocator
    {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        pointer allocate(size_t n = 1)
        {
            return static_cast<pointer>(::operator new(sizeof(value_type) * n));
        }
        void deallocate(pointer p)
        {
            delete[] p;
        }

        template <typename ...Args>
        void construct(pointer p, Args... args)
        {
            new(p) value_type(std::forward<Args>(args)...);
        }

        void destroy(pointer p)
        {
            p->~value_type();
        }
    };
}