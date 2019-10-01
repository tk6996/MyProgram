public class ReadWord {
    static void Main (string[] args) {
        System.Console.WriteLine (readSystem ("a"));
        System.Console.WriteLine (readSystem ("b"));
    }
    public static string readSystem (string megssage = null) {
        System.Console.Write (megssage);
        System.Text.StringBuilder word = new System.Text.StringBuilder ();
        char key;
        while ((key = (char) System.Console.Read ()) >= '\0') {
            if (System.Char.IsWhiteSpace (key)) {
                if (word.Length == 0) continue;
                else break;
            }
            word.Append (key);
        }
        return word.ToString ();
    }
}