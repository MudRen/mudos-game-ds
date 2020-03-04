#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIR"�����x"NOR, ({"red journal","journal"}));
  set("long",@LONG
�@�����֥U�l�A�ݨӴ��g�Q���w�L����o�}��A�̭�����r���ҽk��
�M�F�A���A�`ı�o���䤣��l�A�]�\�A�ˬd(review)�@�U����n�C
LONG
);
  set_weight(400);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",1);
    set("value",0);
  }
  setup(); 
}

void init()
{
  add_action("do_review","review");
}

int do_review(string str)
{
  object me,z;
  me=this_player();

  if(!str || str!="journal") return 0;
  if( me->is_busy() )
    return notify_fail("�A�٦b���A�S�ɶ��ˬd�C\n");
  if(!objectp(z=present("red journal",me) ) )
    return notify_fail("�A�S���F��i�H�ˬd�r�C\n");

  message_vision("\n$N�N��x�J�Ӧa½�\\�A���G��x�T���_�R�ݦӴ����@�a�F�C\n"NOR,me);
  me->start_busy(2);
  call_out("get_paper",1,me);
  return 1;
}

void get_paper(object me)
{
  int i;
  i=0;
  while(i<1)
  {
    if(!random(3))
    {
      message_vision(YEL"\n�q��x�����������X�Ӥ@�i�ϥ֯ȡI\n"NOR,me);
      new(__DIR__"treasure-paper1")->move(environment(this_player()));
      i++;
    }

    if(!random(3))
    {
      message_vision(YEL"\n�q��x�����������X�Ӥ@�i�ϥ֯ȡI\n"NOR,me);
      new(__DIR__"treasure-paper2")->move(environment(this_player()));
      i++;
    }

    if(!random(3))
    {
      message_vision(YEL"\n�q��x�����������X�Ӥ@�i�ϥ֯ȡI\n"NOR,me);
      new(__DIR__"treasure-paper3")->move(environment(this_player()));
      i++;
    }
  }
  destruct(this_object());
}
