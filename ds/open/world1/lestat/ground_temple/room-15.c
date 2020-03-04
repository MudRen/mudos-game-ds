#include <ansi.h>
inherit ROOM;

void create()
{
  set( "short", "�a���������") ;
  set( "long",NOR""
"�e�s���j�U���A�\\�ۤQ�X�L���P���J���A�C�y�J������o�ݮݦp\n"
"�͡A��ض�C�a���ۨө����H�̡A�j�U�����������@�L�S�O���j���p\n"
"���J���A"HIC"�k�ⴤ�C���|"NOR"�A"HIC"������ۦa�U"NOR"�A�����D������S��[�N�C\n"NOR
);
  set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"room-18",
"northwest" : __DIR__"room-16",
"southeast" : __DIR__"room-14",
"southwest" : __DIR__"room-12",
]));
  set("light",0);
  set( "item_desc", ([ /* sizeof() == 1 */
"�J��" : "�p�����J���A��y�����@�����⪺�_�ۡA���C����������G�i�H��ʨ��V(turning)�C\n",
]) );
  set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("thunder_god","turning");
}

int thunder_god(string str)
{
  if (this_object()->query_temp("opened") != 0) return 0;

  if (str=="up" || str=="sky" )
  {
    say(HIY+"�p�������k��Q��V���ۤѪšA�Φ��Ѧa�W�L����...\n"+NOR);
    say(HIY+"�p�����w�w�}�f�D�G�u"+HIW+"�k����ѡA������a�A�ѤW�a�U�A�ߧڿW�L�I"+HIY+"�g�p�}���I�I�v\n"+NOR);
    say(HIW+"�p�����y�����_�۩�X�j�j���q���A�@�ɤ����q���R���|�P�A���A�C���}���I�I\n"+NOR);
    write(HIY+"�A�N�p�������k���ন���V�ѪšA�Φ��Ѧa�W�L����...\n"+NOR);
    write(HIY+"�p�����w�w�}�f�D�G�u"+HIW+"�k����ѡA������a�A�ѤW�a�U�A�ߧڿW�L�I"+HIY+"�g�p�}���I�I�v\n"+NOR);
    write(HIY+"�p�����y�����_�۩�X�j�j���q���A�N�A�ĦV�F���e�誺����I�I\n"+NOR);
    write(HIR+"�b�p�q���������A�A����F����A�X�{�@���q���A�������k�h����...\n"+NOR);

    this_player()->receive_damage("hp",100+random(50));

    set( "exits", ([
"northwest" : __DIR__"room-16",
"northeast" : __DIR__"room-18",
"southwest" : __DIR__"room-12",
"southeast" : __DIR__"room-14",    
"north" : __DIR__"room-17",
]) );

    set( "item_desc", ([
    "�J��" : "�p�����J���A��y�����@�����⪺�_�ۡA���C����w�g�d���ण�ʤF�C\n",
            ]) ); 

    set( "long", @EndText
�e�s���j�U���A�\�ۤQ�X�L���P���J���A�C�y�J������o�ݮݦp
�͡A��ض�C�a���ۨө����H�̡A�j�U�����������@�L�S�O���j���p
���J���A�k�ⴤ�C���ѡA������ۦa�U�A�@�ưߧڿW�L���[�աC
EndText
  );

    set_temp("opened",1);
    return 1;
  }
  write("�A�b����Ӥ���l�ڡH\n");
  return 1;
}

void reset()
{
  set( "long",NOR""
"�e�s���j�U���A�\\�ۤQ�X�L���P���J���A�C�y�J������o�ݮݦp\n"
"�͡A��ض�C�a���ۨө����H�̡A�j�U�����������@�L�S�O���j���p\n"
"���J���A"HIC"�k�ⴤ�C���|"NOR"�A"HIC"������ۦa�U"NOR"�A�����D������S��[�N�C\n"NOR
);

  set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"room-18",
"northwest" : __DIR__"room-16",
"southeast" : __DIR__"room-14",
"southwest" : __DIR__"room-12",
]));

  set( "item_desc", ([ /* sizeof() == 1 */
"�J��" : "�p�����J���A��y�����@�����⪺�_�ۡA���C����������G�i�H��ʨ��V(turning)�C\n",
]) );
  delete_temp("opened");
  ::reset();
}

