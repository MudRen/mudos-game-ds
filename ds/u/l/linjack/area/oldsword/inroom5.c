#include <room.h>
inherit ROOM;
void create()
{
 set("short","�k���U");
 set("long",@LONG
�A�q�L�F�@�Ө��D�Ө�F�k���U, �k���U����î�Q�}�}�L���j��,
�ѩ�o��a�ո����a�Ӫ���, �����S�s, �O�Q���A�X�ݤ�X�������I.
�o�䪺�����\�]�S�����U����@��, ���O�o�]���H�M�����|���Pı,
�p�G�A�Q�n�i�@�B����~���j�j���ݬݭ���, �~���٦��@���p���Y,
�ӧA���W�����Ӷ𤣪��D�O�@����Ϊ�, ���O���Ӱ������ӱ�i�H�W�h.
LONG
    );
 set("exits",([ "east":__DIR__"inroom9",
                "west":__DIR__"inroom66",
                  "up":__DIR__"inroom10",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
