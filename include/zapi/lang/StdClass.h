// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by zzu_softboy on 06/06/2017.

#ifndef ZAPI_LANG_STDCLASS_H
#define ZAPI_LANG_STDCLASS_H

#include "zapi/Global.h"
#include "zapi/lang/Variant.h"

namespace zapi
{
namespace lang
{

class StdClassImpl;

class ZAPI_DECL_EXPORT StdClass
{

private:
   /**
    * Object handle in the PHP engine
    * @var StdClassImpl
    */
   StdClassImpl *m_implPtr = nullptr;

protected:
   /**
    * Constructor
    */
   StdClass()
   {}

   /**
    * Copy constructor
    *
    * This copy constructor is explicitly defined to make sure that the
    * copied object does not already have an implementation in the zend engine.
    * Otherwise the copied object has the same object handle as the original
    * object.
    *
    * @param object
    */
   StdClass(const StdClass &object) : m_implPtr(nullptr)
   {}

public:
   virtual ~StdClass()
   {}

   /**
    * Get access to a property by name using the [] operator
    * @param  string
    * @return Value
    */
   Variant operator[](const char *name) const
   {
      return Variant(this).get(name);
   }

   /**
    * Alternative way to access a property using the [] operator
    * @param  string
    * @return Value
    */
   Variant operator[](const std::string &name) const
   {
      return Variant(this).get(name);
   }

   /**
    * Retrieve a property by name
    * @param  string
    * @return Value
    */
   Variant property(const char *name) const
   {
      return Variant(this).get(name);
   }

   /**
    * Retrieve a property by name
    * @param  string
    * @return Value
    */
   Variant property(const std::string &name) const
   {
      return Variant(this).get(name);
   }

   /**
    * Overridable method that is called right before an object is destructed
    */
   void __destruct() const;

   /**
    * Overridable method that is called right after an object is cloned
    *
    * The default implementation does nothing
    */
   void __clone() const
   {}

   /**
    * Overridable method that is called to check if a property is set
    *
    * The default implementation does nothing, and the script will fall back
    * to accessing the regular object properties
    *
    * @param  key
    * @return bool
    */
   bool __isset(const Variant &key) const;

   /**
    * Overridable method that is called to set a new property
    *
    * The default implementation does nothing, and the script will fall back
    * to accessing the regular object properties
    *
    * @param  key
    * @param  value
    */
   void __set(const Variant &key, const Variant &value) const;

   /**
    * Retrieve a property
    *
    * The default implementation does nothing, and the script will fall back
    * to accessing the regular object properties
    *
    * @param  key
    * @return value
    */
   Variant __get(const Variant &key) const;

   /**
    * Remove a member
    *
    * The default implementation does nothing, and the script will fall back
    * to accessing the regular object properties
    *
    * @param key
    */
   void __unset(const Variant &key) const;

   /**
    * Call a method
    *
    * This method is called when a method is called from the PHP script that
    * was not explicitly defined. You can use this to catch variable method
    * names, or to support all thinkable method names.
    *
    * @param  method      Name of the method that was called
    * @param  params      The parameters that were passed to the function
    * @return Value       The return value
    */
   Variant __call(const char *method, )
};

} // lang
} // zapi

#endif //ZAPI_LANG_STDCLASS_H