#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"�b��"HIC"�P��"NOR,({"elder box","box"}));
        set("unit", "��");
        set("long",@LONG
        
  ��A�@���}�o���_�c�A�A�Q�@�D�G����ģ�ۡA�ϧA�i���}�����A
  ���A��_�L�ӡA�ɤJ�������O��Ӧt�z�A���M�u�O�ӽc�l�A���L
  ���M�p�����j�A�u�O�H�Ĭ��[��A�J�Ӫ��@�F�@�A�o�{���Y�\�F
  �\�h�é_���_���C


  ��F��: put [�F��] in box
  ���F��: get [�F��] from box

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
      set_max_capacity(400);  // 2003.4.16 10000->400  by ksj
        setup();
}
