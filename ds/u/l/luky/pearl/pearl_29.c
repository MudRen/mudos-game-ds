// shop���herb.c
// Luky 1999.1.9�ק�
inherit ROOM;
void create()
{
set("short","[1;35m�R���˳ƥ洫����[m");
set("long",@LONG
�A���i�o�̵oı�Ө�@���M���R��˳ƪ��ө��A�A�ݨ�
�|�g�����F�U���U�˪��޵P�M���C���˳ơA���䪺�����d�h
��F�ǲ��ҩM�A�ˡA��W�K�F�i�`�N�ƶ�(Sign)�C
LONG
);
 set("light",1);
 set("storeroom",__DIR__"temp/shop");//�����|�̦n���۹諸��
 set("exits",([
 "south" : __DIR__"pearl_16",
 ]));
 set("item_desc",([
 "sign":"�Ȱ���~���C\n"
]));
setup();
}
