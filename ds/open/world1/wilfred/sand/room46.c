inherit ROOM;

void armageddon();

void create()
{
  set ("short", "�Y�s�I�m");
  set ("long", @LONG
���B�s�ζ��I�A���p���s�L���A�O�����u���𤧦a�ΡA�s���`�`
�A���}�}�����A�[�W���p�@���e��j�����j�A�ϱo�o�̩{�p�ѵM��
���A�T�Y�����A���H�i�J�C
LONG
);

  set("exits", ([
  "south" : __DIR__"room47",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

void reset()
{
	if( !query("armageddon")
// ||
//    random(4)) {
	) { // random(4) �S�@�Χa-alick
        ::reset();
            return;
    }
        ::reset();
  tell_room(this_object(),"�Y�s�s�S�^�_�F�;� ....\n");

  set ("short", "�Y�s�I�m");
  set ("long", @LONG
���B�s�ζ��I�A���p���s�L���A�O�����u���𤧦a�ΡA�s���`�`
�A���}�}�����A�[�W���p�@���e��j�����j�A�ϱo�o�̩{�p�ѵM��
���A�T�Y�����A���H�i�J�C
LONG
);

  set("exits", ([
  "south" : __DIR__"room47",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  set("no_recall",1);
  delete("armageddon");
  setup();
}

void armageddon()
{
  set ("short", "�o�V");
  set ("long", @LONG

�u���M�a��A�ݫ��ѥˡA�\�J�������G�b�D����
�j�a���L�`�A���ʪ������A���p�W�ʰ����c�������C

�Y�s�s�@�����I�C

LONG
);
  delete("exits");
  delete("no_recall");
  set("armageddon",1);
}

int room_effect(object me)
{
  if(!query("armageddon")) return 1;
  switch(random(5))
  {
    case 1 : tell_room(this_object(),"�@�}�N���j�ӡA�ФH�����G�ۡC\n");
             break;
    case 2 : tell_room(this_object(),"�|�P�@�����I�C\n");
             break;
    case 3 : tell_room(this_object(),"�ѪŪ����O�K�Ǧ⪺�A���a�ʵ��K�ⶳ��A���p�u�u�����C\n");
             break;
    default : return 1;
    }
  return 1;
}

