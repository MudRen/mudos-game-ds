#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIR"�t�����c"NOR,({"fire box","box"}));
        set("unit", "��");
        set("long",@LONG
        
  �@�ӥΨӦs���m�������ũάO���з|�F���̪��p�H���~�C�A�i
  �H��öQ�����~��J�c���O�s�άO�q�c�����X�A�һݭn�����~�C

  ��F��: put [�F��] in box
  ���F��: get [�F��] from box

  �o���_�c���ۯS���\��:
         ** checkuse <box or shelf's id> {-w|-l|-m}
         ** cleanup <box or shelf's id> {get|put|all}
LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); // 2003.4.16  10000->400  by ksj
        set("club_id", "sky");  // BOX_LOG ��
        set("demand_level", 3);  // BOX_LOG ��
        set("access_log",1);
        setup();
}
