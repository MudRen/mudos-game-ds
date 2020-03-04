#include <ansi.h>

#define NAME "���g"
#define ID "(Easy book)"
#define LONG NOR""WHT"\n�i���g�j\n\t�Ĥ@��.�K��²�ϡ��ĤG��.�e�ϡ��ĤT��.���ѡ�\n\t"HIW"�ĥ|�� �񿪤��Q�|�����ǡ��Ĥ��� �K�������t�k\n\n"HIC"�ϥΤ�k: page ����(page 0 ���X�W�ѥ�)\t\t\t"NOR""WHT"�o���Ѧ@������\n\n"NOR
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
    set("unit","��");
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
  if(!arg) return notify_fail("�榡: page ����\n");
  if(!sscanf(arg,"%d",page)) return notify_fail("�榡: page ����\n");
  if(page > 5) return notify_fail("�o���ѥu�������C\n");

  file = resolve_path(__DIR__, obn+(string)page );
  file += ".txt";
  if(page)
    if(file_size(file) < 0)
      return notify_fail(HIR"�A�o�{�Ʊ����ӹ�F�A���S�����W�ӡA�̦n���ֳq���Ův�C\n"NOR);

  long_str = LONG;
  short_str = NAME;
  if(page)
  {
    long_str += read_file(__DIR__+obn+(string)page+ ".txt");
    short_str += NOR""WHT"[��½���"HIY +chinese_number(page)+ NOR""WHT"��]"NOR;
    write("�A�N�ѥ�½���" +chinese_number(page)+ "���C\n" );
  }
  else write("�A�N�ѥ��X�W�C\n");
  return 1;
}

string short() { return short_str + ID; }
string long() { return long_str; }

