inherit BOX;
// �n�~�� box

void create()
{
  set_name("�򥻪��_�c", ({ "default box", "box" }));
  set("long", @LONG
bAsIc BoX.
LONG
  );
  set("value", 1);
  set("unit", "��");
  set_max_encumbrance(999999); // �̤j�t��
  set_max_capacity(99); // �̤j�i�e���~��
  set("cover_name", "�콦�\\"); // �\�l���W��
  set_keys(({ "/example/default_key"})); // �]�w�i�}���_�ͪ��ؿ�+�ɦW
                                // ex: /example/default_key
                                // �i�H�� add_key(string) �ӼW�[
  setup();
  set_cover(4);
// �S�\�l 2 
// �\�l�O���} 3
// �\�l�Q���W 4
// �\�l�Q�}�a 5
  set_lock(8);
// �S�� 6
// ��O�}�� 7
// ��O�W�ꪺ 8
// ��Q�}�a 9
}
