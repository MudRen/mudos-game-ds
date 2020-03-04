#include <ansi.h>
#define UP_DOOR "climb"
#define DOWN_DOOR "out"
inherit ROOM;
int index=1;
int close_time;
int indexp=0;
int stay=1;
//�]�w�ت��a����
string *place=({
"/d/wiz/hall1",
"/u/s/shengsan/workroom",
"/u/l/luky/workroom1",
});
//�۹��place���Ǫ����ɶ�
int *span_time=({25,30,40});
//���ɪ��T��(�C5��@��)
string *float_msg=({
"�M�D�������L�L�a�j�اA���y�U�C\n",
"�@�}�j�����ӡA��A���Ǻ޵�����F�C\n",
"��M���@�����ñq�A���Y�W���L�C\n",
"��w�w���n�F�@�U�C\n",
"��M�������b�q�A�}�Ǳ��X�Y�ӡA�L�F�@�|��S��F�U�h�C\n",
});
void start();
void boat(string);
void swim(int);
string query_filename()
{
  return place[index];
}

int getall()
{
  int i;
  for(i=0;i<sizeof(place);i++)
    if(stay)
      tell_object(this_player(),sprintf("%2d %10s %s %s \n",
           i+1,
           i==indexp ? HIY"�ثe���b->"NOR:"  ",
           place[i]->query("short"),
wiz_level(this_player())>=wiz_level("(apprentice)")?"=> ("+place[i]+")":"
      ));
     else
      tell_object(this_player(),sprintf("%2d %8s %s %s \n",
           i+1,
           i==index ? HIY"�U�@��->"NOR:" ",
           place[i]->query("short"),
 wiz_level(this_player())>=wiz_level("(apprentice)")?"=> ("+place[i]+")":"
"
             ));

  return 1;
}

void create()
{
//seteuid(getuid());
set("short","�j����");
set("name","�j���ɹ");
set("id","cancership");
set("long", @LONG
              ���i�i�i��                  ���i�i�i��
            ���i�i��  ����              ���i��  ���i��
        ���i�i�i��                                 ���i��
     ���i�i�i�i���b�b���i��             ��      ���i�i�i��
      �i�i��  ���i�i�i�i��               ���i�i�i�i��  ���i��
      ���i��                ��          ��               �i��
        ���i�i��            ��          ��           ���i��
             ���i�i�� �b�d�e�g�g�h�i�h�g�g�e�d�b���i�i��
            �b�d�f�h�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�h�f�d�b
    ���i�i�����i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�����i�i��
  ����    �����i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i����    ����
����          ���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i��          ����
        ���i�i���i�i�i�i�h�g�f�e�d�c�d�e�f�g�h�i�i�i�i���i��
      ����      ���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i��    ����
    ����    ���i�����i�i�i�i�i�i�i�i�i�i�i�i�i�i�����i��    ����
    ��    ����    �������i�i�i�i�i�i�i�i�i�i�i������  ����    ��
          �i      �i        ���i�i�i�i�i��        �i    �i
          ��      ����                          ����    �� 
LONG);
set("unit","��");
set("light",1);
set("no_kill",1);
set("ship_long",@LONG
�A�����b�j���ɭI�W���p��x�W�A��x�O�ѼƤQ�������F�α��Ӧ��C
�W�����X��²�檺��ȥH�Τ@�i�諬����l�A�c�T���v�b��O�W�C��l�W���@
�i�a��(Map) �M�@�i��(Note)�C�ѩ�j���ɩ_�S������ߩʡA�ϱo�H�̥i�H��
�K���V�v�Ȧ�A�Ʀܤ����I�N���C

LONG
);
set("item_desc",([
  "note":"\n�ȫȽЪ`�N�H�U�u�h: \n\n"
        +"   1. �ФŶå�U��, �@�P�������Ҿ��.\n"
        +"   2. �i�H��(List)�Ӭݬݪu�~�����a���a�I.\n\n",
  "map":"\n�A�o�{���u�O�@�i�կ�, ���G�٨S�e�n�C\n",
]));
setup();
call_other( "/obj/board/luky_b", "???" );
call_out("boat",0,place[index]->query("short"));
}
void init()
{
        object ob;
        ob=this_player();
        start();
        add_action("getall","list");

}
void start()
{
    object me;
    me=this_player();
    message_vision(HIG"$N�n�W�F"+this_object()->query("name")+" �C\n"NOR,me);
}

void swim(int secs)
{
        int k;
        k=random(7)+6;
        if(secs>7)
        {
                tell_room(this_object(),float_msg[random(sizeof(float_msg))]);
                secs-=k;
                remove_call_out("swim");
                call_out("swim",k,secs);
        }
        else
        {
                tell_room(this_object(),"\n�ڭ̧Y�N��F�ت��a: "+place[index]->query("short")+"\n");
                remove_call_out("swim");
                call_out("boat",7,"�e���� "+place[index]->query("short")+"��");
        }
}

void boat(string ss)
{
  object ob,this_ship,temp_ship,ob1,ob2;
  string s;
  mapping ex;
  this_ship=this_object();
  set("exits",([
  DOWN_DOOR: place[index],
  ]));
  s=sprintf(" %s\n"NOR, (place[index])->query("short"));
  set("long",this_object()->query("ship_long")+HIR"  �j����"HIG"�����a�b"+s+"\n "NOR);
  tell_room(this_object(),HIG"\n  �ڭ̤w�g��F "+place[index]->query("short")+" !!\n\n"NOR);
  tell_room(this_object(),HIW"  �n���}���ȫȽбƶ����}(out)..\n"+NOR+"\n");
  setup();
  ex=place[index]->query("exits");
// add by Nilekil
        ob1=new("/u/l/luky/tempship.c");
        ob2=find_object(place[index]);
        ob1->move(ob2);
  tell_room(place[index],
HIC"�j���ɺC�C����i�F��f.....\n"NOR);
  if(mapp(ex))
  place[index]->set("exits",(mapping)(place[index]->query("exits"))+
  ([ UP_DOOR : base_name(this_object()), ]) );
  else {
    ex=([]);
 ex[UP_DOOR]=base_name(this_object());
    place[index]->set("exits",ex);
  }
  indexp=index;
  index++;
  if(index==sizeof(place)) index=0;
remove_call_out("boat");
close_time=30;
  stay=1;
  call_out("closedoor1",0,"�����a�b "+place[indexp]->query("short"));
}
void closedoor1(string s)
{
  object this_ship,temp_ship,ob1,ob2;
  mapping ex;
  this_ship=this_object();
  if(close_time>10)
  {
        close_time -=10;
        remove_call_out("closedoor1");
        call_out("closedoor1",10,"���a�b "+place[indexp]->query("short"));
  }
  else if(close_time>0)
  {
        tell_room(this_object(),"�٦�" +HIY+sprintf("%d",close_time)+NOR+"��N�n�X�o�F\n");
        tell_room(place[indexp],"�j���ɴN�n�X��F!�Эn�f�����ȫȻ��֪��W��("+UP_DOOR+").....\n"NOR);
        close_time -=5;
        remove_call_out("closedoor1");
        call_out("closedoor1",5,"���a�b "+place[indexp]->query("short"));
  } else 
  {
        tell_room(this_object(),HIW"���ɾ_�ʤF�@�U...�w�w����"+place[index]->query("short")+HIW+"�e�i...\n"NOR);
        // add by nilekil
        ob1=find_object(place[indexp]);
        ob2=present("cancer",ob1); 
        if (!ob2)
        { 
                tell_room(place[indexp],"�j���ɪ����麥���I�U�h�F...\n");
                destruct(this_ship); // Luky
   return;
        } else
        { 
                tell_room(place[indexp],"�j���ɦ����i�y, ����������...\n");
                destruct(ob2);
        }
        tell_room(place[indexp],HIR"�j���ɽw�w�����}�F�����A�}�l��"+
                place[index]->query("short")+HIC"����..\n");
        set("long",this_object()->query("ship_long")+HIR"  �j����"HIG"�{�b���b�e�� "
                +place[index]->query("short")+" ���~��...\n\n"NOR);
   ex=this_object()->query("exits");
   if(mapp(ex)) map_delete(ex,DOWN_DOOR);
   ex=place[indexp]->query("exits");
   if(mapp(ex)) map_delete(ex,UP_DOOR);
   place[indexp]->set("exits",ex);
   remove_call_out("closedoor1");
   stay=0;
//call_out("boat",span_time[index],"�e���� "+place[index]->query("short")+"��");
  call_out("swim",5,span_time[index]);
  }
}

