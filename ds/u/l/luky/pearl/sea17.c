// This is a room made by roommaker.
inherit ROOM;
void create()
{
 set("short", "�שY");
 set("long",@LONG
�o�̬O�@�������שY�A�\�h�p���b������Ӵ�h�C�V���U���N�V�t�A�p�G
���W�S���R�����ө��u���٬O���n�U�h���n�C���䪺���۬ݰ_�ӤQ�����P�n�A  
���G�H�ɳ����˶�U�Ӫ��i��C

LONG
);
set("Env_sector_type","Under_water");
 set("exits", ([ 
  "westup" : __DIR__"sea5",
  "eastdown" : __DIR__"sea18",
  ]));
 set("no_clean_up", 0);
 set("outdoors",1);
 setup();
 replace_program(ROOM);
}
