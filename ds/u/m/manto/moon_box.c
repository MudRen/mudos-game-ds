//2006.6.9 add by manto
#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIW"���"+HIY"�_��"NOR,({"moon box","box"}));
        set("unit", "��");
        set("long",@LONG
�@�Ӫx�۲H������~�B���X�L�L������𮧪��_���C�̭��˵ۤ�ڱo�Ӥ������_���C
  �c�l�����F��X�ӡC
  
  ��F��: put [�F��] in moon box
  ���F��: get [�F��] from moon box

  �o�ӽc�l���ۯS���\��:
         ** checkuse 'box or shelf's id' {-w|-l|-m}
         ** cleanup 'box or shelf's id' {get|put|all}

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); //2003.4.16  10000 -> 400  by ksj
        set("club_id", "moon");
        set("demand_level", 3);
        set("access_log",1);
        setup();
}

