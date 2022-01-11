//条件变量
//本题的目的就是要确保永远都是打印first->second->third
//因此，我们可以使用条件变量控制，first打印完了才能打印second，second打印完了才能打印third
class Foo {
public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        printFirst();
        step = 1;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> ul(mtx);
        cv1.wait(ul, [this]{ return step == 1; });  //循环式wait，当满足step == 1时解除wait阻塞
        printSecond();
        step = 2;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> ul(mtx);
        cv2.wait(ul, [this]{ return step == 2; });
        printThird();
    }
private:
    int step = 0;   //保证顺序
    condition_variable cv1;
    condition_variable cv2;
    mutex mtx;
};