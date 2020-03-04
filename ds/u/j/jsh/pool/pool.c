#include <ansi.h>

inherit ROOM;


void create()
{
        set("short", HIB"���H�P�}"NOR);
        set("long", @LONG 
�o�O�@�]�շt�����}�A���}�W��Q�ۤ@�����¥ժ����ťۡA�w�ۤp�p
���]�A�b��ǡA�ݥߵۼƱ��������A�C�C���۽��L�A�ӫG���}���C�Ӥj�p
�����C�������@������A������G������F�誺�ˤl�C
LONG
        ); 
        set("item_desc",([ 
        "����":"�`�ŵL���������A�b������t�A����ۡy���H�P�}�z�|�� [�j�r]�A�B���䴡�ۤ@�� [��P]�C\n",
        "�j�r":"�y�� �H �P �}�z�C \n",
        "��P":"�@����s���P�l�A�W���g�� [�Фť��Y�����G�Ithrow xxx in pool]�C\n",
        ]) );
        set("exits", ([ /* sizeof() ==  */ 
        "east" : __DIR__"room19",
]));
        set("no_light",1); 
        set("no_recall",1);
        setup();
} 
void init()
{
     add_action("do_throw","throw");
} 
int do_throw(string arg)

{
             object me,x,fruit,z;           
             me = this_player();  
                             
        if(!arg || arg!="fruit in pool") return notify_fail("�A�n���Y����?\n");
        if(!objectp(z=present("fire fruit",me) ) )
                return notify_fail("�A�S���F��i�H��� ? \n");
        message_vision(HIW"$N��X�@��"HIR"�����G�C\n"NOR,me); 
       {
        destruct(z);
    } 

        me->start_busy(2);
switch (random(30) ){ 
                case 16:
                      message_vision("�A���Mť��@�n�G�A�b�F����I�I�I���O�������������G�F�I�S�ݨ�ڥߪ��P�l���I�I\n",me);
                      write("�l�������G�n�p�l�E�E�E�ݧګ��аV�A�I\n");
                      x=new(__DIR__"npc/dan");
                      x->move(this_object());
                      x->kill_ob(this_player()); 
                      me->start_busy(10+random(2));
                      break;
               case 15:
                     message_vision("�A�ݨ�������E�_�@�}�}���������I�C\n",me); 
                     message("world:world1:vision", 
                     HIW"\n\t�d�~���~�E�y�ȪZ���t�z���X�����A���M�ѭ����M�A�[�����h�C\n"NOR,users());
                     message_vision("�ȪZ���t�S�X�@�����L�L���j
�����A���G�Q��A�Q�F��Y�E�E\n",me);
                     x=new(__DIR__"npc/turtle"); 
                     x->move(this_object());  
                     break;
               case 14:
                     message_vision("���M�@�D�¼v�A�e�I�ӹL�A�Ѫŧϩ��t�F�@�b�E�E\n",me);
                     message("world:world1:vision", 
                     HIR"\n\t"+me->name(1)+"�ĳ{�ʦ~����A����i�}�@���E�P�r���I�I\n\n"NOR,users());     
                     x=new(__DIR__"npc/chisel");
                     x->move(this_object());    
                     x->kill_ob(this_player()) ;
                     break;
               case 13:
                     message_vision("������G�٦b�Ť��ɡA�y�x�I�z�����F�A�uť���@�}���n�E�E�E\n",me);
                     message("world:world1:vision",
               
      HIG"\n\t����ӡG��������....�ڦ��ܦh�_���A���O�A�̤H���R�o�_��...��������..\n\n"NOR,users());      
                     x=new(__DIR__"npc/elf");
                     x->move(this_object());  
        break;  
               case 12:
                     message_vision("�����G���������b�Ť��A�y�N�z���@�n�A���i�����̡A�èS���ͤ��򲧪�\n\n",me);
                     break; 
               case 11:
                     message_vision("�����E�X���}�G������,�@�i�i�������|�g�X���ӥh\n"       
                                    "��M!�����B�{�@����������v�I\n",me);  
                     message("world:world1:vision", 
  HIY"\n\t�i���H�P�}�j"+HIR"�ݼɦ��A�A�X����A���}�ͪ��A�L�@�ƧK�C\n"+NOR,users());                                                x=new(__DIR__"npc/snake");
                        x->move(this_object()); 
                        x->kill_ob(this_player());
                        break; 
                case 10:
                      message_vision("�����E�X���}�G������,�@�i�i�������|�g�X���ӥh\n"
                             "��M!�����B�{�@�����������v�I\n",me); 
                        message("world:world1:vision", 
  HIC"\n�i�ʧ@�j"+HIY"�Q�ﳽ(Chi lin-fish)"+HIC"��ۤj�a�j�n�۹D�J�֢�������I�j�a�n��� :D�C\n"+NOR,users()); 
                       x=new(__DIR__"npc/chi-lin-fish");
                       x->move(this_object()); 
                       break; 
                case 9:
                      message_vision("���橿�M�ĥX�@�������I\n"
                      HIW"���������@�{ -_-+�A�i�}��֤j�f�A��"+me->name()+"�r�F�U�h�I�I\n" 
                     +HIR"\t�ˤf�`�i�����I�I"+NOR,me); 
                      message_vision(""+me->name()+"�t�˹L���A�˦a���_....\n",me);
                      me->start_busy(10);
                      me->receive_damage("hp",500+random(222));
                      me->receive_damage("ap",400+random(111));
                      me->receive_damage("mp",600+random(55));
                      break;
                 }  
        return 1;
}

