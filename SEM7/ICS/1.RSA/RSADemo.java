import java.math.*;
import java.security.SecureRandom;

class RSAUtils {
    private final BigInteger modulus;
    private final BigInteger publicKey;
    private final BigInteger privateKey;

    public RSAUtils() {
        BigInteger one = BigInteger.ONE;

        // Take two prime numbers i.e. p1 & p2
        BigInteger primeNumberFirst = BigInteger.probablePrime(40, new SecureRandom());
        BigInteger primeNumberSecond = BigInteger.probablePrime(40, new SecureRandom());

        // Calculate modulus such as (p1 x p2)
        modulus = primeNumberFirst.multiply(primeNumberSecond);

        // Calculate Φ(n) i.e PHI such as (p1 - 1) x (p2 - 1)
        BigInteger PHI = (primeNumberFirst.subtract(one)).multiply(primeNumberSecond.subtract(one));

        // Public key (prime number)
        publicKey = new BigInteger("65537");

        // Calculate private key such as (publicKey ^ -1 % PHI)
        privateKey = publicKey.modInverse(PHI);
    }

    public BigInteger encrypt(BigInteger message) {
        return message.modPow(publicKey, modulus);
    }

    public BigInteger decrypt(BigInteger message) {
        return message.modPow(privateKey, modulus);
    }

    public String getPublicKey() {
        return "" + publicKey.longValue();
    }

    public String getPrivateKey() {
        return "" + privateKey.longValue();
    }

    public String getModulus() {
        return "" + modulus.longValue();
    }
}

class RSADemo {
    public static void main(String[] args) {
        RSAUtils rsa = new RSAUtils();

        String message = "Hello";

        // Generate plain text from message
        BigInteger plainText = new BigInteger(message.getBytes());

        // Encrypt plain text
        BigInteger encryptedMessage = rsa.encrypt(plainText);

        // Decrypt cipher text i.e. previously encrypted message
        BigInteger decryptedMessage = rsa.decrypt(encryptedMessage);

        // Convert encrypted and decrypted messages into plain / readable format
        String encryptedMessageText = new String(encryptedMessage.toByteArray());
        String decryptedMessageText = new String(decryptedMessage.toByteArray());

        String outputString = new StringBuilder()
                .append("\nPublic Key: " + rsa.getPublicKey())
                .append("\nPrivate Key: " + rsa.getPrivateKey())
                .append("\nModulus: " + rsa.getModulus())
                .append("\n\n-+-+-+-+-+-+ MESSAGE TO BE ENCRYPTED +-+-+-+-+-+-")
                .append("\n" + message)
                .append("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-")
                .append("\n\nEncrypted Message: " + encryptedMessageText)
                .append("\nDecrypted Message: " + decryptedMessageText)
                .append("\n")
                .toString();

        System.out.println(outputString);
    }

}