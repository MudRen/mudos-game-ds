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
�谼�i�H�U�h��@���Ŧa.
LONG
    );
 set("exits",([ "north":__DIR__"inroom12",
                "westdown":__DIR__"outroom26",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
