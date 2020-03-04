#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIW"�ե����e"NOR);
        set("long", @LONG 
�A�����b�@���զ⪺�j���e�A���j���z�۲H�H�ե��A���G����
�t�D�`���F��b�̭��A�j�����W���A��ۥե��������|�Ӥj�r�A��
�򯫤u���J��ޥ��A�P�L�L���ե����|�b�@�_�A�Φ��@�ػ����X��
���P�C
LONG
        ); 
        set("item_desc",([ 
        "�ե�����":"�@���զ⪺�j���A�����]�@��[�_�ͤ�(put x in x)]�A���䦳[�ե����_]���ϮסA�O�_�����p�H���o�Ӫ��C\n",
        ]) );
        set("exits", ([ /* sizeof() ==  */ 
        "out" : __DIR__"room11",
]));
        set("light",1); 
        set("no_recall",1);
        setup();
}

void init()
{
     add_action("do_put","put");
}

int do_put(string arg)
{
             object me,x,key,z;           
             me = this_player();  
                             
        if(!arg || arg!="key in �_�ͤ�") return notify_fail("�A�n�񤰻�?\n");
        if(!objectp(z=present("white-light key",me) ) )
                return notify_fail("�A�S���F��i�H��� ? \n");
        message_vision(HIW"$N�N�ե����_��i�F�_�ͤաA�����I�I�ե����_�Q�l�F�i�h�I�����F�C\n"NOR,me); 
       {
        destruct(z);
    } 

        me->start_busy(5);
switch (random(2) ){
               case 0:
                     tell_object(me,"�ժ����}�F.....\n"); 
                     message("world:world1:vision", 
                     HIW"\n\t�ե������b�ե����_����������E�E�E���}�F�E�E�E�C\n"NOR,users()); 
                     write("�ܹFù���G�A����O�P�٪���a�I�I�ݧA�����@�y���ˡI\n");
                     x=new(__DIR__"npc/lou"); 
                     x->move(this_object());   
                     x->kill_object(this_object());                     break;
               case 1:
                     write("����Ƴ��S�o�͡E�Eo.O\n");
                     break;
                 }  
        return 1;
}


