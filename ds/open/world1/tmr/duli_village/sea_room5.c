// File: /d/duli_village/sea_room5.c
// Updated by tmr (Tue May  7 20:44:37 2002)

inherit ROOM;

void create()
{
          set("short", "�j���v���U");
          set("long", @LONG
�A�����b�@�������Ū����v���U�A�A���B�b�o�ӱI�R���@�ɤW�A�C
�C�a�w�g�����M�F�n��_�F�A�L�L�i�ʪ����y�����عL�A�����ߡC����A
�B��L�������@���F�a�ɡA���G�`�N��@���������C
LONG
          );
          set("exits", ([ /* 1 element(s) */
        "up" : __DIR__"sea_room",
]));
        set("detail",([
                  "�F�a":"�A�`�N��b�������@�B���_���F�a�A���G�I�ۤ���F��H\n",
        ]));

        setup();
}
int quest_ok=0;
void reset()
{
        ::reset();
        quest_ok=0;
}
void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me=this_player(),jawei;
        if(!arg || arg!="�F�a")
                return 0;
        if(quest_ok){
                message_vision("$N���⼷���F�F�a�A�o�S���o�{�줰��C\n",me);
        } else {
                jawei=new(__DIR__"npc/obj/jawei");
                if(!jawei->move(me))
                        jawei->move(environment(me));
                message_vision("$N���⼷���F�F�a�A���M�o�{�@�����⪺�_�ۡI\n",me);
		quest_ok=1;
        }
	return 1;
}

