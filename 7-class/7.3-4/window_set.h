#include <string>
#include "window_mgr.h"
class Screen {
// friend class Window_mgr;//整个类作为友元,顺序无所谓先后
friend void Window_mgr::clear(int ScreenIndex); //必须在Screen类之前声明 
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c){ }
    char get() const { return contents[cursor];}
    inline char get(pos ht, pos wd) const;
    inline char get() const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(std::ostream &os) 
        { do_display(os); return *this;}
    Screen &display(std::ostream &os) const
        { do_display(os); return *this;}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const { os << contents;}
};