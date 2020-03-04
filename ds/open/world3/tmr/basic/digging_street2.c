#include <command.h>
#include <path.h>
// Room: /open/world3/tmr/basic/digging_street2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�@���sô�q���P��v�Ϫ������C�ѩ��q�����Ů�D�`�ÿB�A�b������
�Ǧ��j�����Ů�M�s���A��Υi��V���@�n�N��Ϲj���A�O��~���o���
�A���ͬ����ҡC�A���g�N�o�{�A�b�A�}�䪺�@�n���}�F�Ӥp�}�A�_�X�@�\
�\��[0;1;37m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m....
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "��V���@�n" : "�Ѥ@�ؽ��誫��s�����A�u�����G��M�T��q�L�A�ϱo����F����j
�ÿB�Ů𪺮ĪG�C
",
"�զ�����":"���o�ۭ������զ�����A�������������(immerse)���Y�|�p��C\n",
]));
	set("world", "future");
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"digging_street1",
  "south" : __DIR__"digging_street3",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_immerse","immerse");
}

int do_immerse(string arg)
{
        object me,*inv;
        int i;
        string buffer1,file;
        me=this_player();
        if(!arg || arg!="�զ�����") return 0;

        if(me->is_busy()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");

        if(me->query_temp("ride")) 
                return notify_fail("�A���y�M��M���@�N���A�@�_�a�i����....\n");
   if(me->query_temp("killer"))
  {
    write("�A���F�H�Ȯɤ��i�H��V�ɪ�!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("�A�����F���a�Ȯɤ��i�H��V�ɪ�!\n");
    return 1;
  }


        tell_room(environment(me),me->query("name")+"�C�C�a����Ө��麯�i�զ�������Y�F....\n",({me}) );
        inv = all_inventory(me);

        for(i=0; i<sizeof(inv); i++)
        {
        if(inv[i]->query("secured")) 
                inv[i]->delete("secured");
        if(!inv[i]->query("base_value"))
        {
        file=base_name(inv[i]);
        if((sscanf(file,"/open/world2/%s",buffer1)!=1 && sscanf(file,"/open/always/%s",buffer1)!=1 )
                || inv[i]->query_max_encumbrance() > 0)
                {
                if(inv[i]->query("equipped")) inv[i]->unequip();
                DROP_CMD->do_drop(me, inv[i]);
                }
        }
        }
        message("system", "�A��U�@�Ǧh�l�����~, �C�C�����i�զ⪺����C\n\n",me);
        me->move(NOW"anfernee/start/hall3");
        me->set("startroom",NOW"anfernee/start/hall3");
        me->save();
        message("system", "��M�@�}�Ŷ����ᦱ.. �A�S�^��F���x���a��C\n\n",me);
        tell_room(environment(me),me->name()+"��M�X�{�b�A�����e�C\n",({ me }));
        me->start_busy(1);
        return 1;
}

