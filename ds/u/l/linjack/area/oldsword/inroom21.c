#include <room.h>
inherit ROOM;
void create()
{
 set("short","�~���D");
 set("long",@LONG
�V����̦n�������[�I�N�O�o�̤F, �A�񲴱�h, �N�ʨ����[
�ɦ�����, �oı�ۤv�N�n���ĤJ�F���ر��ҷ�, �A���U�ݥh, ��
������e���ˬy, �㭱�𳣬O���ƪ�, �Q�n�q�ˤ��賓�D�L�Ӫ�, 
���o�n�����j�����\���l, �������U�@, �o��]���ƦW�@�æb�ݦu.
���_���i�H�쨫�D�~������W.
LONG
    );
 set("exits",([ "south":__DIR__"inroom12",
                "northdown":__DIR__"outroom16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
