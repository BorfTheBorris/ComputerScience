import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class ContactTest {

    @Test
    public void testContactCreation() {
        Contact contact = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");

        assertEquals("12345", contact.getContactId());
        assertEquals("Kyle", contact.getFirstName());
        assertEquals("McCrea", contact.getLastName());
        assertEquals("1234567890", contact.getPhone());
        assertEquals("123 Main Street", contact.getAddress());
    }

    @Test
    public void testInvalidContactId() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345678901", "Kyle", "McCrea", "1234567890", "123 Main Street");
        });

        assertThrows(IllegalArgumentException.class, () -> {
            new Contact(null, "Kyle", "McCrea", "1234567890", "123 Main Street");
        });
    }

    @Test
    public void testInvalidFirstName() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", null, "McCrea", "1234567890", "123 Main Street");
        });

        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "TooLongName", "McCrea", "1234567890", "123 Main Street");
        });
    }

    @Test
    public void testInvalidLastName() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Kyle", null, "1234567890", "123 Main Street");
        });

        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Kyle", "VeryLongLastName", "1234567890", "123 Main Street");
        });
    }

    @Test
    public void testInvalidPhone() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Kyle", "McCrea", null, "123 Main Street");
        });

        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Kyle", "McCrea", "12345", "123 Main Street");
        });

        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Kyle", "McCrea", "12345abcde", "123 Main Street");
        });
    }

    @Test
    public void testInvalidAddress() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Kyle", "McCrea", "1234567890", null);
        });

        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Kyle", "McCrea", "1234567890", "This address is definitely too long");
        });
    }
}
