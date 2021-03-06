#include <ansi.h>

#define NAME "易經"
#define ID "(Easy book)"
#define LONG NOR""WHT"\n【易經】\n\t第一章.八卦簡圖◎第二章.河圖◎第三章.洛書◎\n\t"HIW"第四章 伏羲六十四卦全傳◎第五章 八卦方位推演法\n\n"HIC"使用方法: page 章數(page 0 為合上書本)\t\t\t"NOR""WHT"這本書共有五章\n\n"NOR
inherit ITEM;

string short_str = NAME;
string long_str = LONG;
void create()
{
  set_name(NAME,({"easy book","book"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",LONG);
    set("value",100);
    set("unit","本");
  }
  setup();
}

void init()
{
  add_action("do_page","page");
}

int do_page(int arg)
{
 int page;
  string file, obn = "easy_book_";
  if(!arg) return notify_fail("格式: page 章數\n");
  if(!sscanf(arg,"%d",page)) return notify_fail("格式: page 章數\n");
  if(page > 5) return notify_fail("這本書只有五章。\n");

  file = resolve_path(__DIR__, obn+(string)page );
  file += ".txt";
  if(page)
    if(file_size(file) < 0)
      return notify_fail(HIR"你發現事情不太對了，但又說不上來，最好趕快通知巫師。\n"NOR);

  long_str = LONG;
  short_str = NAME;
  if(page)
  {
    long_str += read_file(__DIR__+obn+(string)page+ ".txt");
    short_str += NOR""WHT"[正翻到第"HIY +chinese_number(page)+ NOR""WHT"章]"NOR;
    write("你將書本翻到第" +chinese_number(page)+ "章。\n" );
  }
  else write("你將書本合上。\n");
  return 1;
}

string short() { return short_str + ID; }
string long() { return long_str; }

