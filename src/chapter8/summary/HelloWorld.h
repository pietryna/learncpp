#ifndef SRC_CHAPTER8_SUMMARY_HELLOWORLD_H_
#define SRC_CHAPTER8_SUMMARY_HELLOWORLD_H_

namespace exec2
{

class HelloWorld
{
private:
   char *m_data;

public:
   HelloWorld();
   ~HelloWorld();
   void print() const;

};

} /* namespace exec2 */

#endif /* SRC_CHAPTER8_SUMMARY_HELLOWORLD_H_ */
