#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
  set_name(HIM"���"NOR"��ä",({"sakura petal","petal"}));
  set("long", "�@���ո̳z��������ä�A�Q���O�o�C\n");
  set_weight(5);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("eat_msg","$N�X�f��$n�Z��A�I�P���@�f�]�F�U�h�C");
    set("eff_msg",HIM "�Aı�o�|�Ϧ��e�y�ɫD�`�κZ�C" NOR );
  }
        set("value", 300);
        set("heal",([
                "hp": 50,
        ]));
        set("cure",([
                "body": 5,
        ]));
        setup();
}