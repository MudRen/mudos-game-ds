#include <ansi.h>
#include <weapon.h>
inherit SWORD;
mapping chwps = ([
        "blade":                "�M",
        "sword":                "�C",
        "claw":                 "��",
        "fist":                 "��",
        "axe":                  "��",
        "staff":                "��",
        "fork":                 "�j",
        "dagger":               "�P��",
        "hammer":               "��",
        "whip":                 "�@",
]);

void create()
{
  set_name("�s"HIC"�P"NOR"�C"NOR , ({ "dri-star sword","sword" }) ); 
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�s�P�C�A�@��ܻ��몺�C�A�b�⬱�B���ۤ��P�˹�\n"
                "�A�������o�X�@�ѨR���Q�N�C\n"
                "<   �i�H�ϥ�chwp [���A]�@�ഫ�����P�Z��>\n"
    );
    set("material", "gold");
    set("value",50);
  }
  set("weapon_prop/str",20);
  set("weapon_prop/con",20);
  set("weapon_prop/dex",20);
  set("weapon_prop/int",20);  
  set("weapon_prop/bar",3);
  set("weapon_prop/wit",3);
  set("weapon_prop/tec",3);
  set("weapon_prop/dodge",30);
  set("wield_msg",HIW"$N��X$n�A�����g�D��_�}�}�Q��G�H�I\n"NOR);
  set("unwield_msg",HIW"$N��U$n�A�����g�D����H�Q��w�w���h�I\n"NOR);
  init_sword(75+random(15)); 
  setup();
}
int query_autoload() { return 1; }
void init()
{
    add_action("do_chwp","chwp");
}

int do_chwp(string str)
{ 
   object ob = this_object(),me=this_player();
   string *wpty=keys(chwps),wtys;   
   if( ob->query("equipped") )
                         return notify_fail("�Х��Ѱ��˳ơC\n"); 
   if(!str) return notify_fail("chwp [���A]�C\n");
   if(member_array(str,wpty) == -1 )
                      return notify_fail("�S���o���ഫ���A�C\n");
   ob->set("skill_type",str);
   wtys=chwps[str];
   message_vision(
   "$N�⤤��l�j�@�A"HIG"�@�}ģ����"HIY"���~"NOR"�{�L�A�⤤��$n�ܦ��F"HIR+wtys+NOR"���A�C\n"
   ,me,ob);
   ob->set_name("�s"HIC"�P"NOR+wtys,({"dri-star "+str,str}));
   ob->set("long", "�s�P"+wtys+"�A�@��ܻ��몺"+wtys+"�A�b�⬱�B���ۤ��P�˹�\n"
                   "�A�������o�X�@�ѨR���Q�N�C\n"
                   "<   �i�H�ϥ�chwp [���A]�@�ഫ�����P�Z��>\n"
   );
return 1;
}     

 

