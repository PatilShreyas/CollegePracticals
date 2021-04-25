import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

class SHAUtils {
    public static String encrypt(String input) throws NoSuchAlgorithmException {
        // Obtain instance of SHA-1 algorithm
        MessageDigest md = MessageDigest.getInstance("SHA1");

        // Calculate message digest of the input string
        byte[] messageDigest = md.digest(input.getBytes());

        // Convert byte array into numeric representation
        BigInteger no = new BigInteger(1, messageDigest);

        // Convert message digest into hex value
        String hashtext = no.toString(16);

        // Add preceding 0s to make it 32 bit
        while (hashtext.length() < 32) {
            hashtext = "0" + hashtext;
        }

        return hashtext;
    }
}

class SHADemo {

    public static void main(String args[]) throws NoSuchAlgorithmException {
        System.out.println("\n+-+-+-+-+-+-+-+-+-+- SHA-1 Algorithm Example -+-+-+-+-+-+-+-+-+-+");
        System.out.println("\n\nEnter `quit` to exit");

        Scanner scanner = new Scanner(System.in);
        String input;

        System.out.println("\n----------------------------------------------------------------------------------");
        System.out.println("\nINPUT STRING\t\t\tENCRYPTED (SHA-1)");
        System.out.println("\n----------------------------------------------------------------------------------");

        while(true) {
            input = scanner.nextLine();

            if (input.equals("quit")) {
                break;
            }

            String encryptedMessage = SHAUtils.encrypt(input);

            System.out.println("\033[F\r\t\t\t\t" + encryptedMessage);
        }
        System.out.println("----------------------------------------------------------------------------------");
        System.out.println("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
        scanner.close();
    }
}
