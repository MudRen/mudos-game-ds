#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("�LŢ�Y", ({ "food pill","pill" }));
  set("long",
      "�ά��ڽ��B�����B�z�̯��B���e�B�s�A�Τ�������A�M��|���p�Y�l\n"
     +"�ΰ��A�Y�F���F�i�H�R���ٯ���o��������i�C\n"
      );
  set_weight(500);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 200);
  set("heal",([
      "hp": 150,
     ]));
  setup();
}
