#include <ansi.h>
inherit MOBROOM;
void create()
{
        set("short", "�v�޳��ѳ���");
        set("long", @LONG
�A�@�i�ӴN�ݨ�\�h���x�����Ͳr�~�M�@�Ǥ����W���Ǫ��A�j���O
�v�޳��S�a�h��æ�ί���~�W�s�Ү��򪺰ʪ���^�ӵ��_�I�̰V�m�Z
�\�A�b�Ǫ����٦��@�Ǥ�R�R��e�A�H�����|�B�C����ê�L�H�A�b�n
��O�v�޳����j�U�A�p�G�A�ݭn�𮧥i�H�쨺�ܪM���ΦY�W�@�\�C
LONG
        );
        set("exits", ([  "south" : __DIR__"level20", ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        
// /*
        // Mob Room Settings
        set("chance",100);
        set("mob_amount", 4);
        set("mob_object",({
  __DIR__"npc/mtiger",
  __DIR__"npc/rdragon",
}));
// */
        set("outdoors","land");
        set("light",1);
        setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "south" )
                tell_room(environment(me),me->name()+"���v�޳��j�U�����ӥh�C\n",({ me }));
        return ::valid_leave(me, dir);
}

