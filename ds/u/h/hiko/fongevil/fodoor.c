inherit ROOM;
void create()
{
        set("short","���j��");
        set("long",@LONG
�o�̴N�O��񪺤j���f�F�A�i�H�ܲM�����P���񪺧��[�A���O�j��
�K���T�V���F�A�ӥB�Q���O�H��Y���O���O�ϥΩ��۳y���A�b�`�s���n�i
��p���u�{��b�O�j�ӤH�O���O�A�ϧA�L�k���ôb�C
LONG);
        
        set("item_desc", ([
        "�j��" : "�����Ω��۬䦨���j���A�ݨӨI���L��A���W���ӻ���\n",
        "����" : "�s�b�j���W����Ӷ��ɻs�������A�i�H�յۺV��(beat)�ݬ�\n",
        ]));
        set("exits", ([
            "up" : __DIR__"zk13",
        ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init()
{
        add_action("do_beat","beat");
}

int do_beat(string arg)
{
        object me;
        me=this_player();
        if(me->is_busy()) return notify_fail("�A�٦b��\n");
        if(!arg || arg!="����") return notify_fail("�A�n�V����?\n");
        if( query("put_dragon") && query("put_tiger")) //�T�{�аO
          { 
            message_vision("$N�V�F�V������A�j���F���T�F�_�ӡA���M���}�F\n",me);
            set("exits/enter",__DIR__"foin");
            delete("put_dragon");
            delete("put_tiger");
            tell_room(this_object(),"���M�ǨӤ@�}�n���F���N�b1���b��������\n");
            call_out("close_door",90,me); //90�������           
            return 1;
           }
         else
           {
            message_vision("$N�V�F�V�����A����Ʊ��]�S�o��\n",me);
            return 1;
           }
}

void close_door(object me)
{
         delete("exits/enter");
         message_vision("�d������j���S���s���F�_�ӡ��\n",me);
}



