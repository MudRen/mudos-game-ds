#include <room.h>
inherit ROOM;
void create()
{
 set("short","�n�s�~�|");
 set("long",@LONG
�A�j�����F�@��������, �oı�ۤv�����}���I�ĤF, �]��
�o�Ӥs����b�O�Ӱ~�F, �ӥB���S�e, ���|�P�@��, �oı�j�a
�w�g�ɦ��A����, �ӧA�W�������B�����j�������hŢ�n��, ��
���٭n���h�[�~���s���O?
LONG
    );
 set("exits",([
               "eastdown":__DIR__"mount9",
               "southup":__DIR__"mount7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
