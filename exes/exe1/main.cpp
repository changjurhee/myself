#include "../../dlls/dll1/dll1.h"
/*
#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/utility/empty_deleter.hpp>
#include <boost/shared_ptr.hpp>
*/
#include <iostream>

//using namespace boost::log;

int main(int argc, char *argv[])
{
    dll1 iDll1;
    std::cout << iDll1.getText() << std::endl;
    
    /*
    typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
    boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
    
    boost::shared_ptr<std::ostream> stream {&std::clog, boost::empty_deleter{}};
    sink->locked_backend()->add_stream(stream);
    
    core::get()->add_sink(sink);
    
    source::logger lg;
    
    BOOST_LOG(lg) << "note";
    sink->flush();
     */
    
    return 0;
}
