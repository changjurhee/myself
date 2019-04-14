//#define EX4_1
//#define EX25_1

// ex4.1
/*
#include <boost/pool/simple_segregated_storage.hpp>
#include <vector>
#include <cstdef>

int main(){
    boost::simple_segragated_storage<std::size_t> storage;
    std::vector<char> v(1024);
    storage.add_block(&v.front(), v.size(), 256);
    
    int *i = static_cast<int*>(storage_malloc());
    *i = 1;
    
    int *j = static_cast<int*>(storage.malloc_n(1, 512));
    j[10] = 2;
    
    storage.free(i);
    storage_n.free(j,1,512);
}
*/

/*
// ex25.1
#include <boost/property_tree/ptree.hpp>
#include <iostream>

using boost::property::ptree;

int main(){
    ptree pt;
    pt.put("C:.Windows.System", "20 files");
    
    ptree &c = pt.get_child("C:");
    ptree &windows = c.get_child("Windows");
    ptree &system = windows.get_child("System");
    
    std::cout << system.get_value<std::string>() << '\n';
}
*/

// Ex44.7 & Ex44.8 & Ex44.9 & Ex44.10 & Ex4.11
#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <boost/chrono.hpp>
#include <functional>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

void accumulate(boost::promise<int> &p){
    int sum =0 ;
    for(int i=0; i< 5; ++i)
    {
        sum += i;
    }
    
    p.set_value(sum);
}
int accumulate2(){
    int sum =0 ;
    for(int i=0; i< 5; ++i)
    {
        sum += i;
    }
    
    return sum;
}

boost::mutex cond_mutex;
boost::condition_variable_any cond;
std::vector<int> cond_random_numbers;

void fill2()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 3; ++i) {
        boost::unique_lock<boost::mutex> lock{cond_mutex};
        cond_random_numbers.push_back(std::rand());
        cond.notify_all();
        cond.wait(cond_mutex);
    }
}

void print2()
{
    std::size_t next_size = 1;
    for (int i = 0; i < 3; ++i) {
        boost::unique_lock<boost::mutex> lock{cond_mutex};
        while (cond_random_numbers.size() != next_size) {
            cond.wait(cond_mutex);
        }
        std::cout << cond_random_numbers.back() << '\n';
        ++next_size;
        cond.notify_all();
    }
}

void wait(int seconds)
{
    boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
}

boost::mutex mutex;
boost::mutex exclusive_mutex;

void thread()
{
    using boost::this_thread::get_id;
    for (int i = 0; i < 5; ++i) {
        wait(1);
        boost::lock_guard<boost::mutex> lock{mutex};
        std::cout << "Thread " << get_id() << ": " << i << std::endl;
    }
}

void exclusive_thread()
{
    using boost::this_thread::get_id;
    for (int i = 0; i < 5; ++i) {
        wait(1);
        exclusive_mutex.lock();
        std::cout << "exclusive_thread " << get_id() << ": " << i << std::endl;
        exclusive_mutex.unlock();
    }
}

boost::timed_mutex time_mutex;

void thread1()
{
    using boost::this_thread::get_id;
    for (int i = 0; i < 5; ++i) {
        wait(1);
        boost::unique_lock<boost::timed_mutex> lock{time_mutex};
        std::cout << "Thread 1 : " << get_id() << ": " << i << std::endl;
        boost::timed_mutex *m = lock.release();
        m->unlock();
    }
}

void thread2()
{
    using boost::this_thread::get_id;
    for (int i = 0; i < 5; ++i) {
        wait(1);
        boost::unique_lock<boost::timed_mutex> lock{time_mutex, boost::try_to_lock};
        if(lock.owns_lock() || lock.try_lock_for(boost::chrono::seconds{1}))
        {
            std::cout << "Thread 2 : " << get_id() << ": " << i << std::endl;
        }
    }
}

boost::shared_mutex shared_mutex;
std::vector<int> random_numbers;

void fill()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 3; ++i)
    {
        boost::unique_lock<boost::shared_mutex> lock{shared_mutex};
        int temp = std::rand();
        std::cout << "fill thread : " << i << ", " << temp << '\n';
        random_numbers.push_back(temp);
        lock.unlock();
        wait(1);
    }
}

void print()
{
    for (int i = 0; i < 3; ++i)
    {
        wait(1);
        boost::shared_lock<boost::shared_mutex> lock{shared_mutex};
        std::cout << "print thread : " << i << ", " << random_numbers.back() << '\n';
    }
}

int sum = 0;

void count()
{
    for (int i = 0; i < 3; ++i)
    {
        wait(1);
        boost::shared_lock<boost::shared_mutex> lock{shared_mutex};
        sum += random_numbers.back();
        std::cout << "count thread : " << i << ", " << sum << '\n';
    }
}

// EX44.12 & EX44.13

boost::mutex TLS_mutex, TLS_mutex2;

void init(){
    static bool done(false);
    boost::lock_guard<boost::mutex> lock(TLS_mutex);
    if(!done){
        done = true;
        std::cout << "done : " << done << '\n';
    }
    else{
        std::cout << "done : " << done << '\n';
    }
}

void TLS_init(){
    static boost::thread_specific_ptr<bool> tls;
    if(!tls.get()){
        tls.reset(new bool(true));
        boost::lock_guard<boost::mutex> lock{TLS_mutex2};
        std::cout << "tls done" << '\n';
    }
}

void TLS_thread(){
    init();
    init();
}

void TLS2_thread(){
    TLS_init();
    TLS_init();
}

#include <deque>
#include <algorithm>
#include <boost/spirit/include/qi.hpp>
#include <string>
#include <boost/swap.hpp>

using namespace boost::spirit;

#include <boost/math/interpolators/barycentric_rational.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/math/tools/roots.hpp>

int main()
{
    double a1(-5.0);
    double a2(5.0);
    
    double direction = (0 % 2) ? 1.0 : -1.0 ;
    std::cout << a1 << ", " << a2 << ", " << direction << std::endl;
    
    boost::swap(a1, a2);
    
    direction = (1 % 2) ? 1.0 : -1.0 ;
    std::cout << a1 << ", " << a2 << ", " << direction << std::endl;
    
    boost::thread t1(fill), t2(print), t3(count), t4(thread1), t5(thread2), t6(thread), t7(thread), t8(exclusive_thread), t9(exclusive_thread);
    boost::thread t10(fill2), t11(print2);
    boost::thread t[3];
    boost::thread tt[3];
    
    for(int i=0;i<3;i++){
        t[i] = boost::thread{TLS_thread};
        tt[i] = boost::thread{TLS2_thread};
    }
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    
    for(int i=0; i<3; i++){
        t[i].join();
        tt[i].join();
    }
    
    std::cout << "Sum : " << sum << '\n';
    
    boost::promise<int> p;
    boost::future<int> f = p.get_future();
    boost::thread ft{accumulate, std::ref(p)};
    std::cout << "future sum : " << f.get() << std::endl;

    boost::packaged_task<int> task{accumulate2};
    boost::future<int> ff = task.get_future();
    boost::thread ftt{std::move(task)};
    std::cout << "packaged task sum : " << ff.get() << std::endl;
    
    boost::future<int> fasync = boost::async(accumulate2);
    std::cout << "future async sum : " << fasync.get() << std::endl;
    
    std::deque<int> coll = { 1,3,19,5,13,7,11,2,17};
    int x(5), y(12);
    
    auto pos = std::find_if(coll.cbegin(), coll.cend(),
        [=](int i){
            return i >x && i <y ;
        });
    
    auto qqq = [x, &y] {
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        ++y;
    };
    
    std::cout << "first elem >5 and <12 : " << *pos << std::endl;
    
    x = 12;
    
    qqq();
    qqq();
    
    std::cout << "final y: " << y << std::endl;
    
    std::string s;
    std::getline(std::cin, s);
    auto it = s.begin();
    bool match = qi::parse(it, s.end(), ascii::digit);
    bool match2 = qi::phrase_parse(it, s.end(), ascii::digit, ascii::space, qi::skip_flag::dont_postskip);
    std::cout << std::boolalpha << match << ", " << match2 << std::endl;
    if(it != s.end()){
        std::cout << std::string{it, s.end()} << std::endl;
    }
    
    // The lithium potential is given in Kohn's paper, Table I,
    // we could equally use an unordered_map, a list of tuples or pairs,
    // or a 2-dimentional array equally easily:
    std::map<double, double> r;
    
    r[0.02] = 5.727;
    r[0.04] = 5.544;
    r[0.06] = 5.450;
    r[0.08] = 5.351;
    r[0.10] = 5.253;
    r[0.12] = 5.157;
    r[0.14] = 5.058;
    r[0.16] = 4.960;
    r[0.18] = 4.862;
    r[0.20] = 4.762;
    r[0.24] = 4.563;
    r[0.28] = 4.360;
    r[0.32] = 4.1584;
    r[0.36] = 3.9463;
    r[0.40] = 3.7360;
    r[0.44] = 3.5429;
    r[0.48] = 3.3797;
    r[0.52] = 3.2417;
    r[0.56] = 3.1209;
    r[0.60] = 3.0138;
    r[0.68] = 2.8342;
    r[0.76] = 2.6881;
    r[0.84] = 2.5662;
    r[0.92] = 2.4242;
    r[1.00] = 2.3766;
    r[1.08] = 2.3058;
    r[1.16] = 2.2458;
    r[1.24] = 2.2035;
    r[1.32] = 2.1661;
    r[1.40] = 2.1350;
    r[1.48] = 2.1090;
    r[1.64] = 2.0697;
    r[1.80] = 2.0466;
    r[1.96] = 2.0325;
    r[2.12] = 2.0288;
    r[2.28] = 2.0292;
    r[2.44] = 2.0228;
    r[2.60] = 2.0124;
    r[2.76] = 2.0065;
    r[2.92] = 2.0031;
    r[3.08] = 2.0015;
    r[3.24] = 2.0008;
    r[3.40] = 2.0004;
    r[3.56] = 2.0002;
    r[3.72] = 2.0001;
    
    // Let's discover the absissa that will generate a potential of exactly 3.0,
    // start by creating 2 ranges for the x and y values:
    auto x_range = boost::adaptors::keys(r);
    auto y_range = boost::adaptors::values(r);
    boost::math::barycentric_rational<double> b(x_range.begin(), x_range.end(), y_range.begin());
    //
    // We'll use a lamda expression to provide the functor to our root finder, since we want
    // the abscissa value that yields 3, not zero.  We pass the functor b by value to the
    // lambda expression since barycentric_rational is trivial to copy.
    // Here we're using simple bisection to find the root:
    boost::uintmax_t iterations = std::numeric_limits<boost::uintmax_t>::max();
    double abscissa_3 = boost::math::tools::bisect([=](double x) { return b(x) - 3; }, 0.44, 1.24, boost::math::tools::eps_tolerance<double>(), iterations).first;
    std::cout << "Abscissa value that yields a potential of 3 = " << abscissa_3 << std::endl;
    std::cout << "Root was found in " << iterations << " iterations." << std::endl;
    //
    // However, we have a more efficient root finding algorithm than simple bisection:
    iterations = std::numeric_limits<boost::uintmax_t>::max();
    abscissa_3 = boost::math::tools::bracket_and_solve_root([=](double x) { return b(x) - 3; }, 0.6, 1.2, false, boost::math::tools::eps_tolerance<double>(), iterations).first;
    std::cout << "Abscissa value that yields a potential of 3 = " << abscissa_3 << std::endl;
    std::cout << "Root was found in " << iterations << " iterations." << std::endl;
}

/*
//#define EX25_2
#ifndef EX25_2

// ex ; json file read
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

int main(){
    // Short alias for this namespace
    namespace pt = boost::property_tree;
    
    // Create a root
    pt::ptree root;
    
    // Load the json file in this ptree
    pt::read_json("test.json", root);

    // Read values
    int height = root.get<int>("height", 0);
    std::cout << height << '\n';
    
    // You can also go through nested nodes
    std::string msg = root.get<std::string>("some.complex.path");
    std::cout << msg << '\n';
    
    // A vector to allow storing our animals
    std::vector< std::pair<std::string, std::string> > animals;
    
    // Iterator over all animals
    for (pt::ptree::value_type &animal : root.get_child("animals"))
    {
        // Animal is a std::pair of a string and a child
        
        // Get the label of the node
        std::string name = animal.first;
        // Get the content of the node
        std::string color = animal.second.data();
        animals.push_back(std::make_pair(name, color));
        
        std::cout << name << ", " << color << '\n';
    }
    
    std::vector<std::string> fruits;
    for (pt::ptree::value_type &fruit : root.get_child("fruits"))
    {
        // fruit.first contain the string ""
        fruits.push_back(fruit.second.data());
        
        std::cout << fruit.second.data() << '\n';
    }
    
    int matrix[3][3];
    int x = 0;
    for (pt::ptree::value_type &row : root.get_child("matrix"))
    {
        int y = 0;
        for (pt::ptree::value_type &cell : row.second)
        {
            matrix[x][y] = cell.second.get_value<int>();
            std::cout << "[" << x << "," << y << "]" << cell.second.get_value<int>() << '\n';
            y++;
        }
        x++;
    }
    
    // writing JSON
    // Once our ptree was constructed, we can generate JSON on standard output
    pt::write_json(std::cout, root);
    
    // Add values
    height = 5;
    root.put("height", height);
    root.put("some.complex.path", "bonjour");
    
    // Create a node
    pt::ptree animals_node;
    // Add animals as childs
    for (auto &animal : animals)
        animals_node.put(animal.first, animal.second);
    // Add the new node to the root
    root.add_child("animals", animals_node);
    
    // Add two objects with the same name
    pt::ptree fish1;
    fish1.put_value("blue");
    pt::ptree fish2;
    fish2.put_value("yellow");
    root.push_back(std::make_pair("fish", fish1));
    root.push_back(std::make_pair("fish", fish2));
    
    // Add a list
    pt::ptree fruits_node;
    for (auto &fruit : fruits)
    {
        // Create an unnamed node containing the value
        pt::ptree fruit_node;
        fruit_node.put("", fruit);
        
        // Add this node to the list.
        fruits_node.push_back(std::make_pair("", fruit_node));
    }
    root.add_child("fruits", fruits_node);
    
    // Add a matrix
    pt::ptree matrix_node;
    for (int i = 0; i < 3; i++)
    {
        pt::ptree row;
        for (int j = 0; j < 3; j++)
        {
            // Create an unnamed value
            pt::ptree cell;
            cell.put_value(matrix[i][j]);
            // Add the value to our row
            row.push_back(std::make_pair("", cell));
        }
        // Add the row to our matrix
        matrix_node.push_back(std::make_pair("", row));
    }
    // Add the node to the root
    root.add_child("matrix", matrix_node);
    
    pt::write_json("modify.json", root);
    
}
*/

