import 'dart:io';

main() {
  List<int> lists =
      stdin.readLineSync().split(' ').map((e) => int.parse(e)).toList();
  lists.sort();
  for (var order in stdin.readLineSync().split('')) {
    stdout.write('${lists[order.codeUnitAt(0) - 'A'.codeUnitAt(0)]} ');
  }
}
