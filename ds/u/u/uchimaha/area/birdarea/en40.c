#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�A�ݨ�o�઺�Ӫ����~��Z�K, �ӥB�٦h�F�X��
���, �o�̪��Ů�D�`���M�s, �O�A���Q���}, �Q�h��
�X�U, ���Lť���o�̦M������, �٬O���֨��a.
LONG
    );
 
 set("exits",(["northwest":__DIR__"en41",
               "southeast":__DIR__"en39",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
