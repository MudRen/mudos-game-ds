#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name( HIY "������" NOR , ({ "well-moon blade", "blade" }) );
     set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long",@LONG
�o��M�쥻�S���W�r�A�ڶǬO�ӦۤW�j�����L�Q���A����_�ǡA
�M���|���z���~�A�G�ʦ~�e�����J��ɪ��Ĥ@�M�k�a�y�M�Q�z��W�H
��W�C��ӭ�W�H��M�h���A���M�q�����n�θ�A���S���ศ�쿽
�Ѥ⤤�A����S��e���F��A���W���u������v�C
LONG);
    set("material", "gold");
    set("value", 15000);
    set("volume",1);
    set("replica_ob",__DIR__"steel-blade");
  }
        set("limit_str", 40);
        set("limit_con", 40);
        set("limit_level", 35);

    set("weapon_prop/str",2);
    set("weapon_prop/con",2);
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",-1);
    init_blade(85);
  setup();
}

