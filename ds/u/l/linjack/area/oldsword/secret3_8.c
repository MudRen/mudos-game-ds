#include <room.h>
inherit ROOM;
void create()
{
 set("short","�q�D��");
 set("long",@LONG
�q�o�䩹�~���N�X�h�F, �i�O�n�p�ߤ@�X�h�N�S���ۤO���a
�F, �_�M���X�h�γ\�|�L�ӥ|�}�¤�, ���̭����h�O���t�@��.
LONG
    );
 set("exits",([ "southwest":__DIR__"secret3_6",
                "south":__DIR__"outroom17",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
